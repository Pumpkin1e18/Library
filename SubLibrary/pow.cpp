int pow(int x, int n){
	int ans = 1;
	while(n > 0){
		if(n & 1)ans *= x;
		x *= x;
		n >>= 1;
	}
	return ans;
}