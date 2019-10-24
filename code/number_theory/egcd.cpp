int egcd(int a, int b, int& x, int& y) { // a*x + b*y = gcd(a, b) [Bezout's Theorem]
	if (b == 0) return x = 1, y = 0, a;
	int xx, yy;
	int g = egcd(b, a % b, xx, yy);
	x = yy;
	y = xx - (a / b) * yy;
	return g;
}
