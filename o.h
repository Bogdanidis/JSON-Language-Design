class o {
public:
	int a=1;
	class o operator-() {
		return o();

	}

	int  operator--() {
		return 1;

	}
};