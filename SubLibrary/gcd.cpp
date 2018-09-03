int gcd(int a, int b){
	if(a == 0 || b == 0)return max(a, b);
	if(a == b)return a;
	if(a > b)a = a%b;
	else b = b%a;
	return gcd(a, b);
}

int lcm(int a, int b){
	if(a == 0)return 0;
	return a/gcd(a, b)*b;
}