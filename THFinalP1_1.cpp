#include <iostream>
#include <math.h>
using namespace std;

template <class T>


class Poly
{
private:
	int order;	//Degree of polynomial
	T *coeff; //Pointer to create dynamic array of co-efficients
public:
	Poly<T>();						   //Default constructor
	Poly<T>(int, int);				   //Parameterized Constructor
	Poly<T>(int, T *);			   //Parameterized Constructor
	~Poly<T>();					   //Destructor
	Poly<T>(const  Poly<T> &);			   //copy constructor
	Poly<T> &operator=(const Poly<T> &); //Assignment Operator overloading
								   //Mutators and Accessors
	void show();
	void set(T[], int);
	T getOrder() const;
	T *get() const;
	//operator overloading
	Poly operator+(const Poly &);	  //Add two polynomial
	Poly operator-(const Poly &);	  //Substract two polynomial
	Poly operator*(const Poly<T> &);	  //Multiply two polynomial
	Poly operator*(const int);		  //Multiply polynomial with constant
	bool operator==(const Poly &);	  //Check if two polynomial are equal
	//const T &Poly operator[](T i) const; //Returns nth coefficient
	Poly<T> &operator[](T);			  //Returns nth coefficient(lhs)
	int operator()(T);			  //Evaluate P(x) accordingly



	template <typename U>
	friend ostream &operator<<(ostream &Out, const Poly<U> &);
};

template <typename T>
Poly<T>::Poly()
{
	order = 0;
	coeff = new T[order + 1];
	coeff[0] = 1;
}

template <typename T>
Poly<T>::Poly(int Order, int Default)
{
	order = Order;
	coeff = new T[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = Default;
	}
}

template <typename T>
Poly<T>::Poly(int Order, T *Coeff)
{
	order = Order;
	coeff = new T[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = Coeff[i];
	}
}

template <typename T>
Poly<T>::~Poly()
{
	delete[] coeff;
	coeff = nullptr;
}

template <typename T>
Poly<T>::Poly(const  Poly<T> &rhs)
{
	order = rhs.order;
	coeff = new T[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = rhs.coeff[i];
	}
}

template <typename T>
Poly<T> &Poly<T>::operator=(const Poly<T> &rhs)
{
	order = rhs.order;
	coeff = new T[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = rhs.coeff[i];
	}
	return *this;
}

template <typename T>
void Poly<T>::set(T coeff[], int size)
{
	order = size;
	for (int i = 0; i <= size; i++)
	{
		this->coeff[i] = coeff[i];
	}
}

template <typename T>
T Poly<T>::getOrder() const
{
	return order;
}

template <typename T>
T *Poly<T>::get() const
{
	return coeff;
}

template <typename T>
Poly<T> Poly<T>::operator+(const Poly<T> &rhs)
{
	Poly temp;
	int ch = 0;
	if (rhs.order <= order)
	{
		ch = rhs.order;
		temp = *this;
	}
	else
	{
		ch = order;
		temp = rhs;
	}
	for (int i = 0; i <= ch; i++)
	{
		temp.coeff[i] = coeff[i] + rhs.coeff[i];
	}
	return temp;
}

template <typename T>
Poly<T> Poly<T>::operator-(const Poly<T> &rhs)
{
	Poly temp;
	int ch = 0;
	if (rhs.order <= order)
	{
		ch = rhs.order;
		temp = *this;
	}
	else
	{
		ch = order;
		temp = rhs;
	}
	for (int i = 0; i <= ch; i++)
	{
		temp.coeff[i] = coeff[i] - rhs.coeff[i];
	}
	return temp;
}

template <typename T>
Poly<T> Poly<T>::operator*(const int p)
{
	Poly temp(this->order, this->coeff);
	int ch = this->order;

	for (int i = 0; i <= ch; i++)
	{
		temp.coeff[i] = p * temp.coeff[i];
	}
	return temp;
}

template <typename T>
bool Poly<T>::operator==(const Poly<T> &rhs)
{
	if (rhs.order != this->order)
	{
		return false;
	}
	else
	{
		int ch = this->order;
		for (int i = 0; i <= ch; i++)
		{
			if (rhs.coeff[i] != this->coeff[i])
			{
				return false;
			}
		}
		return true;
	}
}

template <typename T>
Poly<T> &Poly<T>::operator[](T n)
{
	int ch = this->order;
	if (n <= ch)
	{
		return this->coeff[n];
	}
	return this->coeff[0];
}

// template <typename T>
// const T &Poly<T>::operator[](T i) const
// {
// 	int ch = this->order;
// 	if (i <= ch)
// 	{
// 		return this->coeff[i];
// 	}
// 	return this->coeff[0];
// }

template <typename T>
int Poly<T>::operator()(T x)
{
	int value = 0;
	for (int i = order; i >= 0; i--)
	{
		if (coeff[i] >= 0)
		{
			if (i == 0)
				value += 1;
			else
				value += pow(coeff[i], i);
		}
		else
		{
			if (i == 0)
				value += 1;
			else
				value += pow(coeff[i], i);
		}
	}
	return value;
}

template <typename T>
Poly<T> Poly<T>::operator*(const Poly<T> &rhs)
{
	int m = getOrder();
	int n = rhs.getOrder();
	int *prod = new T[m + n - 1];
	Poly<T> multi(m + n - 1, 0);


	for (int i = 0; i < m + n - 1; i++)
		multi.coeff[i] = 0;



	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; j++)
			multi.coeff[i + j] += this->coeff[i] * rhs.coeff[j];
	}

	return multi;
}

template <typename T>
void Poly<T>::show()
{
	cout << "Polynomial : ";
	for (int i = order; i >= 0; i--)
	{
		if (coeff[i] >= 0)
		{
			if (i == 0)
				cout << "+" << coeff[i];
			else
				cout << "+" << coeff[i] << "x^" << i;
		}
		else
		{
			if (i == 0)
				cout << coeff[i];
			else
				cout << coeff[i] << "x^" << i;
		}
	}
	cout << endl;
}

template <typename U>
ostream &operator<<(ostream &Out, const Poly<U> &p)
{
	Out << "Polynomial : ";
	for (int i = p.getOrder(); i >= 0; i--)
	{
		if (p.coeff[i] >= 0)
		{
			if (i == 0)
				Out << "+" << p.coeff[i];
			else
				Out << "+" << p.coeff[i] << "x^" << i;
		}
		else
		{
			if (i == 0)
				Out << p.coeff[i];
			else
				Out << p.coeff[i] << "x^" << i;
		}
	}
	Out << endl;
	return Out;
}

int main()
{

string Name;
	/*****************************************/
cout << "Student Enter Name" << endl;
cin >> Name;
cout << "----------------------------------------------" << endl;
cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
cout << "Student Name: " << Name << endl;
cout << "----------------------------------------------" << endl;
	/*****************************************/


	
	cout << "This is the int polynomial operation." << endl;

	int order = 0, *arr = 0;


	cout << "Enter the degree of Polynomial : ";
	cin >> order;
	arr = new int[order + 1];
	cout << "Enter the elements " << endl;
	for (int i = 0; i <= order; i++)
	{
		cout << "For x^" << i << " :";
		cin >> arr[i];
	}
	Poly<int> P1(order, arr);
	Poly<int> P2;
	P1.show();
	cout << "Enter the degree of Polynomial : ";
	cin >> order;
	arr = new int[order + 1];
	cout << "Enter the elements " << endl;
	for (int i = 0; i <= order; i++)
	{
		cout << "For x^" << i << " :";
		cin >> arr[i];
	}
	P2.set(arr, order);
	P2.show();
	Poly<int> P3;
	P3 = P1;
	cout << "P3: ";
	P3.show();
	P3 = P1 + P2;
	P3.show();
	P3 = P2 * 5;
	P3.show();
	cout << P3;
	int Z = P1(2);
	cout << "P1(2) = " << Z << endl;

	
	
	
	
	
	cout << "Now this is the Float Polynomial." << endl;	
		
	int Forder = 0;
	float *Farr = 0;


	cout << "Enter the degree of Polynomial : ";
	cin >> Forder;
	Farr = new float[Forder + 1];
	cout << "Enter the elements " << endl;
	for (int i = 0; i <= Forder; i++)
	{
		cout << "For x^" << i << " :";
		cin >> Farr[i];
	}
	Poly<float> P4(Forder, Farr);
	Poly<float> P5;
	P4.show();
	cout << "Enter the degree of Polynomial : ";
	cin >> Forder;
	Farr = new float[Forder + 1];
	cout << "Enter the elements " << endl;
	for (int i = 0; i <= Forder; i++)
	{
		cout << "For x^" << i << " :";
		cin >> Farr[i];
	}
	P5.set(Farr, Forder);
	P5.show();
	Poly<float> P6;
	P6 = P4;
	cout << "P6: ";
	P6.show();
	P6 = P4 + P5;
	P6.show();
	P6 = P5 * 5;
	P6.show();
	cout << P6;
	int ZF = P4(2);
	cout << "P4(2) = " << ZF << endl;

	
	
}

