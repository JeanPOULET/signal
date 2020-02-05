#include "Signal.h"

#include <iostream>

#include <gtest/gtest.h>

int printou(char arg){
  	printf("CC CV LM : %d\n",arg);
    return 4;
}

void squeezie(char arg, int jose){
  std::cout<<"SAlut à tous c'est SQU"<<arg<<"ZIE j'espère que vous alleral + = "<< jose <<"  !!!\n";
}

TEST(sigTest, firstTest){
  	sig::Signal<void(char,int),sig::DiscardCombiner> sig;
  	//sig.connectSlot(printou);
    sig.connectSlot(squeezie);
	  sig.emitSignal('b',42);
}

int main(int argc, char* argv[]) {
  	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
