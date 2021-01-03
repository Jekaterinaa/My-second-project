#include "pch.h"
#include "../v2.0/studentas.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(AllTests, Vidurkis) {
	vector<float> v = { 7.4, 8.5, 6.9 };
	EXPECT_EQ((float)7.6, vidurkis(v));
}

TEST(Testai, Skaicius) {
	skaicius sk;
	sk.kiek = 100;
	sk.kiek_paz = 5;
	ASSERT_EQ(5, sk.kiek_paz);
}
