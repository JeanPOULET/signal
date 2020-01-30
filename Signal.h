#ifndef SIGNAL_H
#define SIGNAL_H

#include <type_traits>
#include <vector>
#include <functional>

namespace sig {

	/*
	* Combiner that discards all values
	*/
	class DiscardCombiner {
		public:
		using result_type = void;

		template<typename U>
		void combine(const U&) {
			return;
		}

		result_type result() {
			return ;
		}
	};

	/*
	* Combiner that keeps only the last value
	*/
	template<typename T>
	class LastCombiner {
		public:
		using result_type = T;

		template<typename U>
		void combine(const U& item) {

		}

		result_type result() {
			
		}
	};

	/*
	* Combiner that keeps all values in a vector
	*/
	template<typename T>
	class VectorCombiner {
		public:
		using result_type = T;

		template<typename U>
		void combine(const U& item) {

		}

		result_type result() {

		}
	};
	template< class,class >
	class Signal;
	/*
	* A signal
	*/
	template<typename Signature, typename Combiner, class... Args>
	class Signal<Signature(Args...),Combiner> {
		
		public:
		// result of combiner
		using result_type = Signature;
		Combiner combin;
		std::vector<std::function<Signature(Args...)>> save;

		// constructor
		Signal(Combiner combiner = DiscardCombiner()) {
			combin = combiner;
			//std::vector<std::function<Signature(Args)>> save;
		}

		// connect the function to the signal and returns an id
		template<typename Func>
		std::size_t connectSlot(Func callback) {
			save.push_back(callback);
			return save.size();
		}

		// disconnect the function represented by the id
		void disconnectSlot(std::size_t id) {
			save.erase(save.begin()+id);
		}

		// emit a signal, call all the slots
		result_type emitSignal(int args) {
			int resType =-1;
			switch(combin){
				case DiscardCombiner :
					resType = 0;
					void res;
				break;
				case VectorCombiner :
					resType = 1;
					std::vector<result_type> res;
				break;
				default :
					resType = 2;
					result_type res;
				break;
			}
			for(size_t i = 0; i < save.size(); i++){
				if(resType ==1){
					res.push_back(save[i](args));
				}else if (resType ==2){
					res = save[i](args);
				}else{
					save[i](args);
				}
			}
			return res;
		}
  	};

}

#endif // SIGNAL_H
