// MyMatrix.h
// ** Targil 2 **
// Baruch Rosen 208920884 05
// Orit Herman 206924466 09
// Yagel Ashkenazi 208761296 05

#include <iostream>

class MyMatrix
{
	private:
		int m_m;
		int m_n;
		float *m_mat = null;
		
	public:
		MyMatrix(int m = 2, int n = 2, float def_value = 0);
		
		MyMatrix(const MyMatrix& myMat);
		
		~MyMatrix();
		
		// get&set:
			// set size only in the constructor.
			// get and set values, only using Mat[i][j]
		
		int getM();
		int getN();
		
		// operator[][] can throw "out of bounds".
		//// float& operator[](const int m, const int n);
			// that's not so simple to implememt: needed proxy object:..
			// so this isn't the real line in the .h file.
			// https://stackoverflow.com/questions/6969881/operator-overload
			
		// matrix addition, substruction and multiplication can throw "dimensions not agree".
		MyMatrix operator+(MyMatrix& mat2);
		MyMatrix operator-(MyMatrix& mat2);
		MyMatrix operator*(MyMatrix& mat2);
		
		MyMatrix operator-(); // unary minus: new_mat = - old_mat
								// equal to: (-1) * mat
		MyMatrix operator*(float float_const);
		// the opposite operator* with scalar, like 3*Mat, is non-member operator, out of the class.
			// TODO: maybe it can be inside somehow?
			// https://stackoverflow.com/questions/14482380/multiplying-an-object-with-a-constant-from-left-side
		MyMatrix& operator=(MyMatrix& mat2);  // the return value is needed in a = (b = c);
		bool operator==(MyMatrix& mat2);
		std::ostream& friend operator<<(std::ostream& fout, MyMatrix& mat2print);  // print to output stream.
											// the return is for case like: cout << 1 << 2;
											// that equal to (cout << 1) << 2;
}

MyMatrix operator*(float float_const, MyMatrix& mat);