unsigned long int lehmer(long int s) {  
	static unsigned long long a = 2007, b = 4194301, c = 2147483647, z = b;
  	if ( s < 0 ) {
		s = -s; 
		a = s;
	}
	z = (a + b * z) % c;
	return z % s;
}
