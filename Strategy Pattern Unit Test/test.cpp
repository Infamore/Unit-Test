#include "gtest/gtest.h"

#include <string>

#include "op.hpp"

#include "base.hpp"

#include "add.hpp"

#include "sub.hpp"

#include "div.hpp"

#include "mult.hpp"

#include "container.hpp"

#include "VectorContainer.hpp"

#include "sort.hpp"

#include "SelectionSort.hpp"

#include "ListContainer.hpp"

#include "BubbleSort.hpp"



TEST(ContainerTestSet, VectorContainer) {

	Op* seven = new Op(7);

	VectorContainer* test_container = new VectorContainer();

	test_container->add_element(seven);

	ASSERT_EQ(test_container->size(),1);

	EXPECT_EQ(test_container->at(0)->evaluate(), 7);



	test_container->set_sort_function(new SelectionSort());



	Op* thirteen = new Op(13);

	test_container->add_element(thirteen);

	Op* twelve = new Op(12);

	test_container->add_element(twelve);

	test_container->sort();

	EXPECT_EQ(test_container->at(0)->evaluate(), 7);

	EXPECT_EQ(test_container->at(1)->evaluate(), 12);

	EXPECT_EQ(test_container->at(2)->evaluate(), 13);

	



	test_container->swap(1, 2);

	EXPECT_EQ(test_container->at(1)->evaluate(), 13);

        EXPECT_EQ(test_container->at(2)->evaluate(), 12);

}





TEST(ContainerTestSet, ListContainer) {

        Op* seven = new Op(7);

        ListContainer* test_container = new ListContainer();

        test_container->add_element(seven);

        ASSERT_EQ(test_container->size(),1);

        EXPECT_EQ(test_container->at(0)->evaluate(), 7);



        test_container->set_sort_function(new SelectionSort());



        Op* thirteen = new Op(13);

        test_container->add_element(thirteen);

        Op* twelve = new Op(12);

        test_container->add_element(twelve);

        test_container->sort();

        EXPECT_EQ(test_container->at(0)->evaluate(), 7);

        EXPECT_EQ(test_container->at(1)->evaluate(), 12);

        EXPECT_EQ(test_container->at(2)->evaluate(), 13);





        test_container->swap(1, 2);

        EXPECT_EQ(test_container->at(1)->evaluate(), 13);

        EXPECT_EQ(test_container->at(2)->evaluate(), 12);

}





TEST(SortTestSet, SelectionSortTest) {

    Op* seven = new Op(7);

    Op* four = new Op(4);

    Mult* TreeA = new Mult(seven, four);



    Op* three = new Op(3);

    Op* two = new Op(2);

    Add* TreeB = new Add(three, two);



    Op* ten = new Op(10);

    Ope* six = new Op(6);

    Sub* TreeC = new Sub(ten, six);



    VectorContainer* container = new VectorContainer();

    container->add_element(TreeA);

    container->add_element(TreeB);

    container->add_element(TreeC);



    ASSERT_EQ(container->size(), 3);

    EXPECT_EQ(container->at(0)->evaluate(), 28);

    EXPECT_EQ(container->at(1)->evaluate(), 5);

    EXPECT_EQ(container->at(2)->evaluate(), 4);



    container->set_sort_function(new SelectionSort());

    container->sort();



    ASSERT_EQ(container->size(), 3);

    EXPECT_EQ(container->at(0)->evaluate(), 4);

    EXPECT_EQ(container->at(1)->evaluate(), 5);

    EXPECT_EQ(container->at(2)->evaluate(), 28);

}





TEST(SortTestSet, SelectionSortTest) {

    Op* seven = new Op(7);

    Op* four = new Op(4);

    Mult* TreeA = new Mult(seven, four);



    Op* three = new Op(3);

    Op* two = new Op(2);

    Add* TreeB = new Add(three, two);



    Op* ten = new Op(10);

    Ope* six = new Op(6);

    Sub* TreeC = new Sub(ten, six);



    ListContainer* container = new ListContainer();

    container->add_element(TreeA);

    container->add_element(TreeB);

    container->add_element(TreeC);



    ASSERT_EQ(container->size(), 3);

    EXPECT_EQ(container->at(0)->evaluate(), 28);

    EXPECT_EQ(container->at(1)->evaluate(), 5);

    EXPECT_EQ(container->at(2)->evaluate(), 4);



    container->set_sort_function(new BubbleSort());

    container->sort();



    ASSERT_EQ(container->size(), 3);

    EXPECT_EQ(container->at(0)->evaluate(), 4);

    EXPECT_EQ(container->at(1)->evaluate(), 5);

    EXPECT_EQ(container->at(2)->evaluate(), 28);

}
