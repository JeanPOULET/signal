#include "Signal.h"
#include <iostream>
#include <gtest/gtest.h>

														/*********************************************************
														 * 						TEST RETURN VOID				 *
														 * *******************************************************/

TEST(sigTest, Test_UnParamCharReturnVoidDiscardCombiner){
  	sig::Signal<void(char),sig::DiscardCombiner> sig;
	std::function<void (char)> funct = [] (char arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal('Y');
}

TEST(sigTest, Test_UnParamIntReturnVoidDiscardCombiner){
  	sig::Signal<void(int),sig::DiscardCombiner> sig;
	std::function<void (int)> funct = [] (int arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(42);
}

TEST(sigTest, Test_UnParamDoubleReturnVoidDiscardCombiner){
  	sig::Signal<void(double),sig::DiscardCombiner> sig; 
	std::function<void (double)> funct = [] (double arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(42.42);
}

TEST(sigTest, Test_UnParamBoolReturnVoidDiscardCombiner){
  	sig::Signal<void(bool),sig::DiscardCombiner> sig;
	std::function<void (bool)> funct = [] (bool arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(true);
}

TEST(sigTest, Test_UnParamStringReturnVoidDiscardCombiner){
  	sig::Signal<void(std::string),sig::DiscardCombiner> sig;
	std::function<void (std::string)> funct = [] (std::string arg){std::cout<<arg<<"\n";};
    sig.connectSlot(funct);
	std::string str = "Carotte";
	sig.emitSignal(str);
}

TEST(sigTest, Test_DeuxParamCharReturnVoidDiscardCombiner){
  	sig::Signal<void(char, char),sig::DiscardCombiner> sig;
	std::function<void (char, char)> funct = [] (char arg, char arg2){std::cout<<arg<<" "<<arg2<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal('Y', 'Z');
}

TEST(sigTest, Test_DeuxParamCharIntReturnVoidDiscardCombiner){
  	sig::Signal<void(char, int),sig::DiscardCombiner> sig;
	std::function<void (char, int)> funct = [] (char arg, int arg2){std::cout<<arg<<" "<<arg2<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal('Y', 2);
}

TEST(sigTest, Test_DeuxParamIntReturnVoidDiscardCombiner){
  	sig::Signal<void(int, int),sig::DiscardCombiner> sig;
	std::function<void (int, int)> funct = [] (int arg, int arg2){std::cout<<arg<<" "<<arg2<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(4, 2);
}

TEST(sigTest, Test_DeuxParamIntBoolReturnVoidDiscardCombiner){
  	sig::Signal<void(int, bool),sig::DiscardCombiner> sig;
	std::function<void (int, bool)> funct = [] (int arg, bool arg2){std::cout<<arg<<" "<<arg2<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(2, true);
}

TEST(sigTest, Test_DeuxParamDoubleReturnVoidDiscardCombiner){
  	sig::Signal<void(double, double),sig::DiscardCombiner> sig;
	std::function<void (double, double)> funct = [] (double arg, double arg2){std::cout<<arg<<" "<<arg2<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(4.2, 2.4);
}

TEST(sigTest, Test_DeuxParamDoubleBoolReturnVoidDiscardCombiner){
  	sig::Signal<void(double, bool),sig::DiscardCombiner> sig;
	std::function<void (double, bool)> funct = [] (double arg, bool arg2){std::cout<<arg<<" "<<arg2<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(2.4, true);
}

TEST(sigTest, Test_DeuxParamBoolReturnVoidDiscardCombiner){
  	sig::Signal<void(bool, bool),sig::DiscardCombiner> sig;
	std::function<void (bool, bool)> funct = [] (bool arg, bool arg2){std::cout<<arg<<" "<<arg2<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(true, false);
}

TEST(sigTest, Test_DeuxParamBoolIntReturnVoidDiscardCombiner){
  	sig::Signal<void(bool, int),sig::DiscardCombiner> sig;
	std::function<void (bool, int)> funct = [] (bool arg, int arg2){std::cout<<arg<<" "<<arg2<<"\n";};
    sig.connectSlot(funct);
	sig.emitSignal(true, 5);
}

TEST(sigTest, Test_DeuxParamStringReturnVoidDiscardCombiner){
  	sig::Signal<void(std::string, std::string),sig::DiscardCombiner> sig;
	std::function<void (std::string, std::string)> funct = [] (std::string arg, std::string arg2){std::cout<<arg<<" "<<arg2<<"\n";};
    sig.connectSlot(funct);
	std::string str1 = "cc";
	std::string str2 = "bb";
	sig.emitSignal(str1, str2);
}

TEST(sigTest, Test_DeuxParamStringIntReturnVoidDiscardCombiner){
  	sig::Signal<void(std::string, int),sig::DiscardCombiner> sig;
	std::function<void (std::string, int)> funct = [] (std::string arg, int arg2){std::cout<<arg<<" "<<arg2<<"\n";};
    sig.connectSlot(funct);
	std::string str = "cc";
	sig.emitSignal(str, 5);
}

TEST(sigTest, Test_CinqParamAllTypesReturnVoidDiscardCombiner){
  	sig::Signal<void(std::string, int, double, char, bool),sig::DiscardCombiner> sig;
	std::function<void (std::string, int, double, char, bool)> funct = [] (std::string arg, int arg2, double arg3, char arg4, bool arg5){std::cout<<arg<<" "<<arg2<<" "<<arg3<<" "<<arg4<<" "<<arg5<<"\n";};
    sig.connectSlot(funct);
	std::string str = "cc";
	sig.emitSignal(str, 5, 4.2, 'c', false);
}

														/*********************************************************
														 * 						TEST RETURN INT					 *
														 * *******************************************************/

TEST(sigTest, Test_UnParamCharReturnIntLastCombiner){
  	sig::Signal<int(char),sig::LastCombiner<int>> sig;
	std::function<int (char)> funct = [] (char arg){return arg+5;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal('Y');
	EXPECT_EQ('Y'+5, res);
}

TEST(sigTest, Test_UnParamIntReturnIntLastCombiner){
  	sig::Signal<int(int),sig::LastCombiner<int>> sig;
	std::function<int (int)> funct = [] (int arg){return arg+5;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal(5);
	EXPECT_EQ(5+5, res);
}

TEST(sigTest, Test_UnParamDoubleReturnIntLastCombiner){
  	sig::Signal<int(double),sig::LastCombiner<int>> sig;
	std::function<int (double)> funct = [] (double arg){return arg+5;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal(4.2);
	EXPECT_EQ(9, res);
}

TEST(sigTest, Test_UnParamBoolReturnIntLastCombiner){
  	sig::Signal<int(bool),sig::LastCombiner<int>> sig;
	std::function<int (bool)> funct = [] (bool arg){if(arg){return 5;} return 0;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal(true);
	EXPECT_EQ(5, res);
}

TEST(sigTest, Test_UnParamStringReturnIntLastCombiner){
  	sig::Signal<int(std::string),sig::LastCombiner<int>> sig;
	std::function<int (std::string)> funct = [] (std::string arg){if(arg == "cc"){return 5;}return 0;};
	int res;
	std::string str = "cc";
    sig.connectSlot(funct);
	res = sig.emitSignal(str);
	EXPECT_EQ(5, res);
}

TEST(lotFuncs, Test_PleinsFonctions){
  	sig::Signal<int(),sig::LastCombiner<int>> sig;
	std::function<int ()> funct1 = [] (){return -2;};
	std::function<int ()> funct2 = [] (){return 4;};
	std::function<int ()> funct3 = [] (){return 3;};
	std::function<int ()> funct4 = [] (){return 16;};
	int res;

    sig.connectSlot(funct1);
	sig.connectSlot(funct2);
	sig.connectSlot(funct3);
	sig.connectSlot(funct4);
	res = sig.emitSignal();
	EXPECT_EQ(16, res);
}

TEST(lotFuncs, Test_PleinsFonctions_retourVoid){
  	sig::Signal<void(int),sig::DiscardCombiner> sig;
	std::function<void (int)> funct1 = [] (int s){std::cout<<s<<"\n";};
	std::function<void (int)> funct2 = [] (int s){std::cout<<s+1<<"\n";};
	std::function<void (int)> funct3 = [] (int s){std::cout<<s+2<<"\n";};
	std::function<void (int)> funct4 = [] (int s){std::cout<<s+3<<"\n";};
	int res;

    sig.connectSlot(funct1);
	sig.connectSlot(funct2);
	sig.connectSlot(funct3);
	sig.connectSlot(funct4);
	sig.emitSignal(16);
}

int main(int argc, char* argv[]) {
  	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
