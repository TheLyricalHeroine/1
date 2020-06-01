class CVector0 : public CVector {
	public:
	
	CVector0();
	CVector0(double *v1, int len1, string FileName1);
	CVector0(int len2);
	CVector0(const CVector& other);
	
	using CVector::operator=;
	friend CVector0 operator+(CVector& first, CVector& second);
	friend CVector0 operator-(CVector& first, CVector& second);
	
	void output();
	
};