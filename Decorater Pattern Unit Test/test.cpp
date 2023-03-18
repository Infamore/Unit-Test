#include "gtest/gtest.h"

#include <string>

#include "op.hpp"

#include "base.hpp"

#include "add.hpp"

#include "sub.hpp"

#include "div.hpp"

#include "mult.hpp"

#include "ceil.hpp"

#include "floor.hpp"

#include "abs.hpp"

#include "trunc.hpp"

#include "par.hpp"

#include "decorator.hpp"



using namespace std;



TEST(ceiltest, ceil) {

	Op* operand = new Op(7.7);

	Ceil* ceil = new Ceil(operand);

	

	EXPECT_EQ(ceil->evaluate(), 8);

}



TEST(floortest, floored) {

	Op* operand = new Op(7.4);

	Floor* floor = new Floor(operand);



	EXPECT_EQ(floor->evaluate(), 7);





}



TEST(abstest, abs) {

	Op* operand = new Op(-6);

	Abs* abs = new Abs(operand);



	EXPECT_EQ(abs->evaluate(), 6);





}



TEST(trunctest, truncate) {

	Add* add = new Add(new Op(3), new Sub(new Op(4), new Op(2)));

	Trunc* trunc = new Trunc(add);

	

	

	EXPECT_EQ(add->getright()->stringify(), "4 - 2");

	EXPECT_EQ(trunc->stringify(), "3 + 2");



}





TEST(partest, par) {

	Sub* sub = new Sub(new Op(3), new Op(4));

	Par* par = new Par(sub);



	EXPECT_EQ(par->stringify(), "(3 - 4)");	



}



int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}

