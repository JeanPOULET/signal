#include "Signal.h"
#include <iostream>
#include <gtest/gtest.h>

																			/*********************************************************
																			 * 						TEST VOID						 *
																			 * *******************************************************/

TEST(sigTest, Test_UnParamCharReturnVoidDiscardCombiner){
  	sig::Signal<void(char),sig::DiscardCombiner> sig;
	std::function<void (char)> funct = [] (char arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal('Y');
}

TEST(sigTest, Test_UnParamIntReturnVoidDiscardCombiner){
  	sig::Signal<void(char),sig::DiscardCombiner> sig;
	std::function<void (int)> funct = [] (int arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(42);
}

TEST(sigTest, Test_UnParamDoubleReturnVoidDiscardCombiner){
  	sig::Signal<void(char),sig::DiscardCombiner> sig; 
	std::function<void (double)> funct = [] (double arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(42.42);
}

TEST(sigTest, Test_UnParamBoolReturnVoidDiscardCombiner){
  	sig::Signal<void(char),sig::DiscardCombiner> sig;
	std::function<void (bool)> funct = [] (bool arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(true);
}
/*
TEST(sigTest, Test_UnParamStringReturnVoidDiscardCombiner){
  	sig::Signal<void(char),sig::DiscardCombiner> sig;
	std::function<void (std::string)> funct = [] (std::string arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	std::string str = "Carotte";
	sig.emitSignal(str);
}

TEST(sigTest, Test_UnParamVectorReturnVoidDiscardCombiner){
  	sig::Signal<void(char),sig::DiscardCombiner> sig;
	std::function<void (std::vector<int>)> funct = [] (std::vector<int> arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	std::vector<int> vec = {5, 6,7};
	sig.emitSignal(vec);
}
*/




int main(int argc, char* argv[]) {
  	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
