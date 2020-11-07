TEST(classtesting, opclass) {
        op* temp = new op(12);
        EXPECT_EQ(12, temp->evaluate());
        EXPECT_EQ("12", temp->stringify());

}


TEST(classtesting, addclass) {
        op* op1 = new op(9);
        op* op2 = new op(5);
        add* temp = new add(op1, op2);
        EXPECT_EQ(14, temp->evaluate());
  			EXPECT_EQ("9 + 5", temp->stringify());
}
          
TEST(classtesting, subclass) {
        op* op1 = new op(17);
        op* op2 = new op(14);
        sub* temp = new sub(op1, op2);
        EXPECT_EQ(3, temp->evaluate());
        EXPECT_EQ("17 - 14", temp->stringify());

}

TEST(classtesting, multclass) {
        op* op1 = new op(7);
        op* op2 = new op(3);
        mult* temp = new mult(op1, op2);
        EXPECT_EQ(21, temp->evaluate());
        EXPECT_EQ("7 * 3", temp->stringify());


}
          
TEST(classtesting, divclass) {
        op* op1 = new op(15);
        op* op2 = new op(3);
        Div* temp = new Div(op1, op2);
        EXPECT_EQ(5, temp->evaluate());
        EXPECT_EQ("15 / 3"), temp->stringify());


}

TEST(classtesting, powclass) {
        op* op1 = new op(2);
        op* op2 = new op(5);
        Pow* temp = new Pow(op1, op2);
        EXPECT_EQ(32, temp->evaluate());
        EXPECT_EQ("2 ** 5", temp->stringify());

}

TEST(classtesting, expressiontrees) {
      op* op1(5);
  		op* op2(3);
  		op* op3(3);
  		op* op4(2);
			//evaluate 
			mult* temp = new mult(op1, op2);
  		Div* temp1 = new Div(temp, op3);
  		add* temp2 = new add(temp1, op4);

			EXPECT_EQ(7, temp2->evaluate()); //temp2 should have the final calculation of the arithmetic
			//stringify
			EXPECT_EQ("5 * 3 / 3 + 2", op1->stringify() + " * " + op2->stringify() + " / " + op3->stringify() + " + " + op4->stringify());
}

////////make sure that googletest folder is in lab3 directory so gtest compilation will work unless its already there
////////$ git submodule add https://github.com/google/googletest.git 
////////^^^^^link to googletest repository^^^^^^
////////CMakeList.txt 
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)


ADD_EXECUTABLE(test
        test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
////////all tests should pass
