#include "Signal.h"

#include <iostream>

#include <gtest/gtest.h>

int printou(char arg){
  	printf("CC CV LM : %d\n",arg);
}

void squeezie(char arg){
 	std::cout<<"SAlut à tous c'est SQU"<<arg<<"ZIE j'espère que vous aller mal !!!\n";
}

TEST(sigTest, firstTest){
  	sig::Signal<void(char),sig::DiscardCombiner> sig;
  	sig.connectSlot(printou);
    sig.connectSlot(squeezie);
	sig.emitSignal('b');

}

int main(int argc, char* argv[]) {
  	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
