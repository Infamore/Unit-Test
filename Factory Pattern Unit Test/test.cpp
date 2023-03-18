#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "Rand.hpp"
#include "Op.hpp"
#include "PrecisionOp.hpp"
#include "PrecisionRand.hpp"
#include "SciOp.hpp"
#include "SciRand.hpp"
#include "BaseFactory.hpp"
#include "RegFactory.hpp"
#include "PrecisionFactory.hpp"
#include "SciFactory.hpp"
#include "gtest/gtest.h"


TEST(Precision, ops)
{
  PrecisionOp* temp = new PrecisionOp(7.455491);
  EXPECT_EQ("7.4555", temp->stringify());
}

TEST(Precision, rands)
{
  string holdstring;
  PrecisionRand* temp = new PrecisionRand();
  holdstring = temp->stringify();
  EXPECT_EQ(holdstring, temp->stringify());
}

TEST(Sci, ops)
{
  SciOp* temp = new SciOp(7455491);
  EXPECT_EQ("7.45549e+06", temp->stringify());
}


TEST(Sci, rands)
{
  string holdstring;
  SciRand* temp = new SciRand();
  holdstring = temp->stringify();
  EXPECT_EQ(holdstring, temp->stringify());
}

TEST(factory, regs)
{
  double val = 3;
  double randval;
  regFactory* temp = new regFactory();
  op* op1 = temp->createOp(val);
  EXPECT_EQ(val, op1->evaluate());
  regFactory* temp1 = new regFactory();
  Rand* rand = temp1->createRand();
  randval = rand->evaluate();
  EXPECT_EQ(randval, rand->evaluate());
}


TEST(factory, precisions)
{
  double val = 7.455491;
  string randstr;
  PrecisionFactory* temp = new PrecisionFactory();
  op* op1 = temp->createOp(val);
  EXPECT_EQ("7.4555", op1->stringify());

  regFactory* temp1 = new regFactory();
  Rand* rand = temp1->createRand();
  randstr = rand->stringify();
  EXPECT_EQ(randstr, rand->stringify());
}


TEST(factory, scientific)
{
  double val = 7455491;
  string randstr;
  SciFactory* temp = new SciFactory();
  op* op1 = temp->createOp(val);
  EXPECT_EQ("7.45549e+06", op1->stringify());

  SciFactory* temp1 = new SciFactory();
  Rand* rand = temp1->createRand();
  randstr = rand->stringify();
  EXPECT_EQ(randstr, rand->stringify());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
