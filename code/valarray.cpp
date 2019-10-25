#include<valarray> 
// apply and sum
valarray<int> varr = { 10, 2, 20, 1, 30 }; 
valarray<int> varr1 = varr.apply([](int x){return x=x+5;}); 
varr1.sum()
// min and max
valarray<int> varr = { 10, 2, 20, 1, 30 }; 
varr.max()
varr.min()
// shift and cshift
valarray<int> varr = { 10, 2, 20, 1, 30 }; 
valarray<int> varr1 = varr.shift(2); // {20, 1, 30, 0, 0}
varr1 = varr.cshift(-3); // {20, 1, 30, 10, 2}
// swap
valarray<int> varr = { 10, 2, 20, 1, 30};
valarray<int> varr1 = { 2, 29, 3, 1, 41};
varr.swap(varr1);

