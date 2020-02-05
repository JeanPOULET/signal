#include "Signal.h"
#include <iostream>
#include <gtest/gtest.h>

														/*********************************************************
														 * 						TEST RETURN VOID				 *
														 * *******************************************************/

TEST(sigTest, Test_ZeroParamReturnVoidDiscardCombiner){
  	sig::Signal<void(),sig::DiscardCombiner> sig;
	std::function<void ()> funct = [] (){std::cout<<"Bonjour\n";};
    sig.connectSlot(funct);
	sig.emitSignal();
}

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

TEST(sigTest, Test_ZeroParamReturnIntLastCombiner){
  	sig::Signal<int(),sig::LastCombiner<int>> sig;
	std::function<int ()> funct = [] (){return 5;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal();
	EXPECT_EQ(5, res);
}

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

TEST(sigTest, Test_DeuxParamCharReturnIntLastCombiner){
  	sig::Signal<int(char, char),sig::LastCombiner<int>> sig;
	std::function<int (char, char)> funct = [] (char arg, char arg2){return arg+arg2;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal('Y', 'Z');
	EXPECT_EQ('Y'+'Z', res);
}

TEST(sigTest, Test_DeuxParamCharIntReturnIntLastCombiner){
  	sig::Signal<int(char, int),sig::LastCombiner<int>> sig;
	std::function<int (char, int)> funct = [] (char arg, int arg2){return arg+arg2;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal('Y', 5);
	EXPECT_EQ('Y'+5, res);
}

TEST(sigTest, Test_DeuxParamIntReturnIntLastCombiner){
  	sig::Signal<int(int, int),sig::LastCombiner<int>> sig;
	std::function<int (int, int)> funct = [] (int arg, int arg2){return arg+arg2;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal(5, 5);
	EXPECT_EQ(5+5, res);
}

TEST(sigTest, Test_DeuxParamIntBoolReturnIntLastCombiner){
  	sig::Signal<int(int, bool),sig::LastCombiner<int>> sig;
	std::function<int (int, bool)> funct = [] (int arg, bool arg2){if(arg2){return arg+5;}return 0;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal(5, true);
	EXPECT_EQ(5+5, res);
}

TEST(sigTest, Test_DeuxParamDoubleReturnIntLastCombiner){
  	sig::Signal<int(double, double),sig::LastCombiner<int>> sig;
	std::function<int (double, double)> funct = [] (double arg, double arg2){return arg+arg2;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal(4.2, 2.4);
	EXPECT_EQ(4+2, res);
}

TEST(sigTest, Test_DeuxParamDoubleBoolReturnIntLastCombiner){
  	sig::Signal<int(double, bool),sig::LastCombiner<int>> sig;
	std::function<int (double, bool)> funct = [] (double arg, bool arg2){if(!arg2){return arg+5;}return arg;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal(4.2, false);
	EXPECT_EQ(9, res);
}

TEST(sigTest, Test_DeuxParamBoolReturnIntLastCombiner){
  	sig::Signal<int(bool, bool),sig::LastCombiner<int>> sig;
	std::function<int (bool, bool)> funct = [] (bool arg, bool arg2){if(arg && arg2){return 5;} return 0;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal(true, true);
	EXPECT_EQ(5, res);
}

TEST(sigTest, Test_DeuxParamBoolIntReturnIntLastCombiner){
  	sig::Signal<int(bool, int),sig::LastCombiner<int>> sig;
	std::function<int (bool, int)> funct = [] (bool arg, int arg2){if(arg){return arg2;} return 0;};
	int res;
    sig.connectSlot(funct);
	res = sig.emitSignal(true, 5);
	EXPECT_EQ(5, res);
}

TEST(sigTest, Test_DeuxParamStringReturnIntLastCombiner){
  	sig::Signal<int(std::string, std::string),sig::LastCombiner<int>> sig;
	std::function<int (std::string, std::string)> funct = [] (std::string arg, std::string arg2){if(arg == "cc" && arg2 == "bb"){return 5;}return 0;};
	int res;
	std::string str = "cc";
	std::string str2 = "bb";
    sig.connectSlot(funct);
	res = sig.emitSignal(str, str2);
	EXPECT_EQ(5, res);
}

TEST(sigTest, Test_DeuxParamStringIntReturnIntLastCombiner){
  	sig::Signal<int(std::string, int),sig::LastCombiner<int>> sig;
	std::function<int (std::string, int)> funct = [] (std::string arg, int arg2){if(arg == "cc"){return arg2;}return 0;};
	int res;
	std::string str = "cc";
    sig.connectSlot(funct);
	res = sig.emitSignal(str, 5);
	EXPECT_EQ(5, res);
}

														/*********************************************************
														 *					TEST RETURN VECTOR<INT>				 *
														 * *******************************************************/


TEST(sigTest, Test_ZeroParamReturnIntVectorCombiner){
  	sig::Signal<int(),sig::VectorCombiner<int>> sig;
	std::function<int ()> funct = [] (){return 5;};
	std::function<int ()> funct1 = [] (){return 55;};
	std::vector<int> res;

    sig.connectSlot(funct);
	sig.connectSlot(funct1);

	res = sig.emitSignal();

	EXPECT_EQ(5, res[0]);
	EXPECT_EQ(55, res[1]);
}

TEST(sigTest, Test_UnParamCharReturnIntVectorCombiner){
  	sig::Signal<int(char),sig::VectorCombiner<int>> sig;
	std::function<int (char)> funct = [] (char arg){return arg+5;};
	std::function<int (char)> funct1 = [] (char arg){return arg+4;};
	std::vector<int> res;

    sig.connectSlot(funct);
	sig.connectSlot(funct1);

	res = sig.emitSignal('Y');

	EXPECT_EQ('Y'+5, res[0]);
	EXPECT_EQ('Y'+4, res[1]);
}

TEST(sigTest, Test_UnParamIntReturnIntVectorCombiner){
  	sig::Signal<int(int),sig::VectorCombiner<int>> sig;
	std::function<int (int)> funct = [] (int arg){return arg+5;};
	std::function<int (int)> funct1 = [] (int arg){return arg+4;};
	std::vector<int> res;
	
    sig.connectSlot(funct);
	sig.connectSlot(funct1);

	res = sig.emitSignal(5);

	EXPECT_EQ(10, res[0]);
	EXPECT_EQ(9, res[1]);
}

														/*********************************************************
														 *					TEST PLEIN DE FONCTIONS				 *
														 * *******************************************************/
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
    sig.connectSlot(funct1);
	sig.connectSlot(funct2);
	sig.connectSlot(funct3);
	sig.connectSlot(funct4);
	sig.emitSignal(16);
}

TEST(lotFuncs, Test_PleinsFonctions_retourPriviet){
  	sig::Signal<int(int,int),sig::LastCombiner<int>> sig;
	std::function<int (int,int)> funct1 = [] (int s, int ss){return s+ss+5;};
	std::function<int (int,int)> funct2 = [] (int s, int ss){return s+ss+10;};
	std::function<int (int,int)> funct3 = [] (int s, int ss){return s+ss+15;};
	std::function<int (int,int)> funct4 = [] (int s, int ss){return s+ss+20;};
    sig.connectSlot(funct1);
	sig.connectSlot(funct2);
	sig.connectSlot(funct3);
	sig.connectSlot(funct4);
	int res = sig.emitSignal(8,4);
	EXPECT_EQ(8+4+20,res);
}

TEST(lotFuncs, Test_PleinsFonctions_retourPatchimou){
  	sig::Signal<int(int,int),sig::VectorCombiner<int>> sig;
	std::vector<int> vec = {8+4+5,8+4+10,8+4+15,8+4+20};
	std::function<int (int,int)> funct1 = [] (int s, int ss){return s+ss+5;};
	std::function<int (int,int)> funct2 = [] (int s, int ss){return s+ss+10;};
	std::function<int (int,int)> funct3 = [] (int s, int ss){return s+ss+15;};
	std::function<int (int,int)> funct4 = [] (int s, int ss){return s+ss+20;};
    sig.connectSlot(funct1);
	sig.connectSlot(funct2);
	sig.connectSlot(funct3);
	sig.connectSlot(funct4);
	std::vector<int> res = sig.emitSignal(8,4);
	EXPECT_EQ(vec,res);
}

int main(int argc, char* argv[]) {
  	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
