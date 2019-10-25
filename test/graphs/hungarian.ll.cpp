#include <bits/stdc++.h>
using namespace std;
typedef long long num;
const num eps = 0;
const int N = 112;
#include "gtest/gtest.h"
#include "../../code/graphs/hungarian.cpp"

void full_check(const hungarian &h) {
	for(int i = 0; i < h.n; i++) {
		ASSERT_NE(h.MA[i], -1);
		EXPECT_EQ(i, h.MB[h.MA[i]]);
	}
	for(int i = 0; i < h.n; i++)
		for(int j = 0; j < h.n; j++)
			EXPECT_LE(h.y[i] + h.z[j], h.c[i][j]);
}

TEST(Hungarian, Simple) {
	hungarian h;
	h.n = 1;
	h.c[0][0] = 2;
	EXPECT_EQ(h.min_match(), 2);
	full_check(h);
	h.n = 2;
	h.c[0][0] = 2;
	h.c[1][1] = 2;
	h.c[0][1] = 1;
	h.c[1][0] = 1;
	EXPECT_EQ(h.min_match(), 2);
	EXPECT_EQ(h.MA[0], 1);
	EXPECT_EQ(h.MA[1], 0);
	full_check(h);
	h.c[0][0] = -2;
	EXPECT_EQ(h.min_match(), 0);
	EXPECT_EQ(h.MA[0], 0);
	EXPECT_EQ(h.MA[1], 1);
	full_check(h);
}

TEST(Hungarian, Break) {
	hungarian h;
	h.n = 2;
	h.c[0][0] = 3;
	h.c[0][1] = 3;
	h.c[1][0] = 2;
	h.c[1][1] = 0;
	EXPECT_EQ(h.min_match(), 3);
	full_check(h);
}

TEST(Hungarian, Random) {
	for(int t = 0; t < 10; t++) {
		hungarian h;
		h.n = 100;
		for(int i = 0; i < h.n; i++)
			for(int j = 0; j < h.n; j++)
				h.c[i][j] = (rand() % 100) - 50;
		h.min_match();
		full_check(h);
	}
}
