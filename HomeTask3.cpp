#include <iostream>
#include <windows.h>
#include <string>


using namespace std;

class Shape
{
protected:
	string name;
	int side_number = 0;

public:
	Shape(string setName = "Фигура", int setSideNumber = 0) : name{ setName }, side_number{ setSideNumber }{};

	string get_name()const
	{
		return name;
	}

	int get_side_number()const
	{
		return side_number;
	}

	virtual bool check()
	{
		if (side_number == 0) return true;
	};

	std::string print_check(bool check) const
	{
		std::string check_result = "";
		if (check == true) check_result = "Правильная фигура";
		else check_result = "Неправильная фигура";
		return check_result;
	};
	virtual void print_info()
	{
		cout << get_name() << endl;
		cout << print_check(check()) << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
	};
};

class Triangle : public Shape
{
protected:
	int a_side = 0;
	int b_side = 0;
	int c_side = 0;

	int angle_A = 0;
	int angle_B = 0;
	int angle_C = 0;

public:
	Triangle(int setA_side, int setB_side, int setC_side, int setAngle_A, int setAngle_B, int setAngle_C, string setName= "Треугольник:", int setSideNumber = 3) : a_side{ setA_side }, b_side{ setB_side }, c_side{ setC_side }, angle_A{ setAngle_A }, angle_B{ setAngle_B }, angle_C{ setAngle_C }, Shape(setName, setSideNumber){}

	bool check()override
	{
		if ((angle_A + angle_B + angle_C == 180) && (get_side_number() ==3))
			return true;
	};
	void print_info() override
	{
		cout << get_name() << endl;
		cout << print_check(check()) << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + "\n";
	};
};

class RangleTriangle : public Triangle
{
protected:
	int angle_C = 90;
public:
	RangleTriangle(int setA_side, int setB_side, int setC_side, int setAngle_A, int setAngle_B, int setAngle_C=90, string setName = "Прямоугольный треугольник:", int setSideNumber = 3
	) :Triangle(setA_side, setB_side, setC_side, setAngle_A, setAngle_B, setAngle_C,setName, setSideNumber) {}

	bool check() override
	{
		if (Triangle::check() == true) 
		{
			if (angle_C == 90)
				return true;
		}
	};

	void print_info() override
	{
		cout << get_name() << endl;
		cout << print_check(check()) << endl;
		cout << "количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + "\n";
	};

};

class IsoscelesTriangle : public Triangle
{
public:

	IsoscelesTriangle(int setA_side, int setB_side, int setAngle_A, int setAngle_B, string setName = "Равнобедренный треугольник:", int setSideNumber=3 
	) :Triangle(setA_side, setB_side, setA_side, setAngle_A, setAngle_B, setAngle_A,setName, setSideNumber) {}

	bool check() override
	{
		if (Triangle::check() == true)
		{
			if ((a_side == c_side) && (angle_A == angle_C))
				return true;
		}
	};
	void print_info() override
	{
		cout << get_name() << endl;
		cout << print_check(check()) << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + "\n";
	};
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
	EquilateralTriangle(int setA_side, int setAngle_A=60, string setName= "Равносторонний треугольник:", int setSideNumber = 3) :IsoscelesTriangle(setA_side, setA_side, setAngle_A, setAngle_A, setName, setSideNumber) {}

	bool check() override
	{
		if (IsoscelesTriangle::check() == true)
		{
			if ((a_side == b_side) && (angle_A == angle_B))
				return true;
		}
	}
	void print_info() override
	{
		cout << get_name() << endl;
		cout << print_check(check()) << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + "\n";
	}
};

class Quadrangle : public Shape
{
protected:
	int a_side = 0;
	int b_side = 0;
	int c_side = 0;
	int d_side = 0;

	int angle_A = 0;
	int angle_B = 0;
	int angle_C = 0;
	int angle_D = 0;
public:
	Quadrangle(int setA_side, int setB_side, int setC_side, int setD_side, int setAngle_A, int setAngle_B, int setAngle_C, int setAngle_D, string setName = "Четырёхугольник:", int setSideNumber=4
	) : a_side{ setA_side }, b_side{ setB_side }, c_side{ setC_side }, d_side{ setD_side }, angle_A{ setAngle_A }, angle_B{ setAngle_B }, angle_C{ setAngle_C }, angle_D{ setAngle_D }, Shape(setName, setSideNumber){}

	bool check() override
	{
		if ((angle_A + angle_B + angle_C + angle_D == 360) && (get_side_number() == 4))
			return true;
	}
	void print_info() override
	{
		cout << get_name() << endl;
		cout << print_check(check()) << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + " d = " + to_string(d_side)+"\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + " D = " + to_string(angle_D)+"\n";
	}
};

class Parallelogram :public Quadrangle
{
public:
	Parallelogram(int setA_side, int setB_side, int setAngle_A, int setAngle_B, string setName = "Параллелограмм:", int setSideNumber = 4
	) :Quadrangle(setA_side, setB_side, setA_side, setB_side, setAngle_A, setAngle_B, setAngle_A, setAngle_B, setName, setSideNumber) {}

	bool check() override
	{
		if (Quadrangle::check() == true)
		{
			if ((a_side == c_side) && (b_side == d_side) && (angle_A == angle_C) && (angle_B == angle_D))
				return true;
		}
	}
	void print_info() override
	{
		cout << get_name() << endl;
		cout << print_check(check()) << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + " d = " + to_string(d_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + " D = " + to_string(angle_D) + "\n";
	}
};

class Rectangl :public Parallelogram
{
public:
	Rectangl(int setA_side, int setB_side, int setAngle_A=90, string setName = "Прямоугольник:",int setSideNumber = 4) :Parallelogram(setA_side, setB_side, setAngle_A, setAngle_A, setName, setSideNumber) {}

	bool check() override
	{
		if (Parallelogram::check() == true)
		{
			if (angle_B == 90)
				return true;
		}
	}
	void print_info() override
	{
		cout << get_name() << endl;
		cout << print_check(check()) << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + " d = " + to_string(d_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + " D = " + to_string(angle_D) + "\n";
	}
};

class Square :public Rectangl
{
public:
	Square(int setA_side, int setAngle_A = 90, string setName = "Квадрат:", int setSideNumber = 4) :Rectangl(setA_side, setA_side, setAngle_A, setName, setSideNumber) {}

	bool check() override
	{
		if (Rectangl::check() == true)
		{
			if ((a_side == d_side) && (angle_A == angle_D))
				return true;
		}
	}
	void print_info() override
	{
		cout << get_name() << endl;
		cout << print_check(check()) << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + " d = " + to_string(d_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + " D = " + to_string(angle_D) + "\n";
	}
};

class Rhomb :public Parallelogram
{
public:
	Rhomb(int setA_side, int setAngle_A, int setAngle_B, string setName = "Ромб:") :Parallelogram(setA_side, setA_side, setAngle_A, setAngle_B, setName) {}

	bool check() override
	{
		if (Parallelogram::check() == true)
		{
			if ((a_side == d_side))
				return true;
		}
	}
	void print_info() override
	{
		cout << get_name() << endl;
		cout << print_check(check()) << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + " d = " + to_string(d_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + " D = " + to_string(angle_D) + "\n";
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Shape shape1;
	shape1.print_info();
	cout << endl;
	cout << endl;

	Triangle triangle1(10,20,30,50,60,70);
	triangle1.print_info();
	cout << endl;
	cout << endl;

	RangleTriangle rantr1(10, 20, 30, 50, 60);
	rantr1.print_info();
	cout << endl;
	cout << endl;


	
	RangleTriangle rantr2(10,20,30,50,40);
	rantr2.print_info();
	cout << endl;
	cout << endl;

	IsoscelesTriangle istr1(10,20,50,60);
	istr1.print_info();
	cout << endl;
	cout << endl;
	
	EquilateralTriangle eqlatr1(30);
	eqlatr1.print_info();
	cout << endl;
	cout << endl;
	
	Quadrangle quadrangle1(10,20,30,40,50,60,70,80);
	quadrangle1.print_info();
	cout << endl;
	cout << endl;
	
	Rectangl rect1(10,20);
	rect1.print_info();
	cout << endl;
	cout << endl;

	Square square1(10);
	square1.print_info();
	cout << endl;
	cout << endl;

	Parallelogram parall1(20, 30,60,120);
	parall1.print_info();
	cout << endl;
	cout << endl;

	Rhomb rhomb1(30,30,40);
	rhomb1.print_info();
	cout << endl;

	return 0;
}

