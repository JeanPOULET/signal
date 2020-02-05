#ifndef SIGNAL_H
#define SIGNAL_H

#include <type_traits>
#include <string>
#include <vector>
#include <functional>
#include <map>

namespace sig {

	/*
	* Combiner that discards all values
	*/
	class DiscardCombiner {
		public:
		using result_type = void;

		template<typename U>
		void combine(U&&) {
	
		}

		result_type result() {

		}
	};

	/*
	* Combiner that keeps only the last value
	*/
	template<typename T>
	class LastCombiner {
		public:
		using result_type = T;
		result_type res;
		template<typename U>
		void combine(U&& item) {
			res = item;
		}

		result_type result() {
			return res;
		}
	};

	/*
	* Combiner that keeps all values in a vector
	*/
	template<typename T>
	class VectorCombiner {
		public:
		using result_type = std::vector<T>;
		std::vector<T> vec;
		template<typename U>
		void combine(U&& item) {
			vec.push_back(item);
		}

		result_type result() {
			return vec;
		}
	};

	template< class,class Combiner = DiscardCombiner() >
	class Signal;
	/*
	* A signal
	*/
	template<class R, typename Combiner, class... Args>
	class Signal<R(Args...),Combiner> {
		
		public:
		// result of combiner
		using result_type = typename Combiner::result_type;
		Combiner combin;
		std::map<std::size_t,std::function<R(Args...)>> save;
		std::size_t act_id =0;
		// constructor
		Signal(Combiner combiner = DiscardCombiner()) {
			combin = combiner;
		}

		// connect the function to the signal and returns an id
		template<typename Func>
		std::size_t connectSlot(Func callback) {
			save.insert(std::pair<std::size_t,Func>(act_id,callback));
			return save.size();
		}

		// disconnect the function represented by the id
		void disconnectSlot(std::size_t id) {
			save.erase(id);
		}

		// emit a signal, call all the slots
		result_type emitSignal(Args ...args) {

			for(size_t i=0; i<save.size();++i){
				R item = save[i](args...);
				combin.combine(item);
			}

			if(!std::is_same<void,result_type>::value){
				return combin.result();
			}
		}
  	};

	template<typename Combiner, class... Args>
	class Signal<void(Args...),Combiner> {
		
		public:
		// result of combiner
		using result_type = typename Combiner::result_type;
		Combiner combin;
		std::map<std::size_t ,std::function<void(Args...)>> save;
		std::size_t act_id =0;

		// constructor
		Signal(Combiner combiner = DiscardCombiner()) {
			combin = combiner;
		}

		// connect the function to the signal and returns an id
		template<typename Func>
		std::size_t connectSlot(Func callback) {
			save.insert({act_id,callback});
			act_id++;
			return act_id-1;
		}

		// disconnect the function represented by the id
		void disconnectSlot(std::size_t id) {
			save.erase(id);
		}

		// emit a signal, call all the slots
		result_type emitSignal(Args ...args) {

			for(size_t i=0; i<save.size();++i){
				save[i](args...);
			}
		}
  	};

}

#endif // SIGNAL_H
