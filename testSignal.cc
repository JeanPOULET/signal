#include "Signal.h"

#include <iostream>

#include <gtest/gtest.h>

void printou(int arg){
  printf("CC CV LM : %d",arg);
}

TEST(sigTest, firstTest){
  	sig::Signal<void(int)> sig;
  	sig.connectSlot(printou);
	sig.emitSignal(1);

}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
