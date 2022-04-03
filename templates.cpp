#include <iostream>
#include <stdlib.h>
using namespace std;



template <class T>
class Array{
public:
     // constructors
     Array(int itsSize = 1);
     Array(const Array &rhs);           //copy constructor
     ~Array( ) {delete [] pType;}       //destructor

     // operators
     Array<T>& operator=(const Array<T>&);
    T& operator[](int offSet);
	 T& operator[](int offSet) const;

     // accessors
     int GetitsSize() const { return itsSize; }

  // friend function
template <class U>friend ostream& operator<< (ostream&, const Array<U>& rhs);

//Overloaded arithmetic operators
void operator++(){
for(int i = 0; i< this->itsSize; i++) { 
this->itsSize;
}
}		//increments each element of array by one 


 private:
     T * pType;
     int  itsSize;
 };
//T represent the data type(int, float, double, char, string)

template <class T>
 Array<T>::Array(int size):
 itsSize(size)
 {
     pType = new T[size];
     for (int i = 0; i<size; i++)
         pType[i] = (T)0;
 }

template <class T>
 Array<T> & Array<T>::operator=(const Array<T> &rhs)
 {
     if (this == &rhs)
         return *this;
     delete [] pType;
     itsSize = rhs.GetitsSize();
     pType = new T[itsSize];
     for (int i = 0; i<itsSize; i++)
         pType[i] = rhs[i];
     return *this;
 }
 
 template <class T>
 Array<T>::Array(const Array &rhs)
 {
     itsSize = rhs.GetitsSize();
     pType = new T[itsSize];
     for (int i = 0; i<itsSize; i++)
         pType[i] = rhs[i];
 }
 
 template <class T>
 T& Array<T>::operator[](int offSet)
{
	return pType[offSet];
 }


template <class T>
  T& Array<T>::operator[](int offSet) const
 {

	return pType[offSet];
	
 }


template<typename U>
ostream& operator<<(ostream& output, const Array<U>& rhs) {

	for(int i = 0; i < rhs.itsSize; i++) {
	
	output << rhs.pType[i] << endl;
	
	
	}

return output;

}


int main() {


string Name;
	/*****************************************/
cout << "Student Enter Name" << endl;
cin >> Name;
cout << "----------------------------------------------" << endl;
cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
cout << "Student Name: " << Name << endl;
cout << "----------------------------------------------" << endl;
	/*****************************************/

const int N = 16;
Array<int>X(N);
Array<float>Y(N);
const Array<char>C(N);



for(int h = 0; h < N; h++){
X[h] = h * 2;
Y[h] = h * 2;
C[h] = 'a' + h;
}


cout << "This is the INT array." << endl;
cout << X << endl;

cout << "This is the FLOAT array." << endl;
cout << Y << endl;

cout << "This is the CHAR array." << endl;
cout << C << endl;

int value = X[4];

cout << "This is the value of X[4] = " << value << endl; 

Y[5] = Y[6] + Y[7];

cout << "This is the FLOAT array after the change." << endl << Y << endl;

for(int h = 0; h < N -1; h++){

Y[h] = 10*Y[h];

}

cout << "This is the FlOAT array after the scalar change." << endl << Y << endl;


return 0;













}
