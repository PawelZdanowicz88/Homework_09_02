#include <iostream>
#include <exception>
class Fraction
{
public:
	int numerator_;
	int denominator_;
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	int getNum()
	{
		return numerator_;
	}
	int getDen()
	{
		return denominator_;
	}
	Fraction LCD() // поиск найменьшего общего знаменателя
	{
		int num = numerator_;
		int den = denominator_;
		int a = 0;
		int b = 0;
		int c = 1;  
		int i = 0; // найбольший общий делитель
		if ((den == 0)||(num == 0))
		{
			return Fraction(0, 0);
		}
		if (den > num) // для поиска несократимого общего делителя определим что больше, числитель или знаменатель
		{
			a = den;
			b = num;
		}
		else
		{
			a = num;
			b = den;
		} 
		
		do // a=b*q+c алгоритм Евклида (каждое С - это остаток от деления предыдущего числа на предыдущее, а предпоследнее (i) делится на последнее нацело - это и есть несократимый общий делитель)
		{
			i = c;
			c = a % b;
			a = b;
			b = c;
		} while (c > 0);
		return Fraction(num/i, den/i);
	}
	Fraction operator + (Fraction f2)
	{
		int num = (this->numerator_ * f2.denominator_) + (f2.numerator_ * this->denominator_);
		int den = this->denominator_ * f2.denominator_;
		return Fraction (num, den);
	}
	Fraction operator - (Fraction f2)
	{
		int num = (this->numerator_ * f2.denominator_) - (f2.numerator_ * this->denominator_);
		int den = this->denominator_ * f2.denominator_;
		return Fraction(num, den);
	}
	Fraction operator * (Fraction f2)
	{
		int num = this->numerator_ * f2.numerator_;
		int den = this->denominator_ * f2.denominator_;
		return Fraction(num, den);
	}
	Fraction operator / (Fraction f2)
	{
		int num = this->numerator_ * f2.denominator_;
		int den = this->denominator_ * f2.numerator_;
		return Fraction(num, den);
	}
	Fraction operator - ()
	{
		int num = numerator_;
		num = -numerator_;
		return Fraction(num, denominator_);
	}
	Fraction& operator ++ ()
	{
		numerator_ += denominator_;
		return *this;
	}
	Fraction operator ++ (int)
	{
		Fraction prev = *this;
		++(*this);
		return prev;
	}
	Fraction& operator -- ()
	{
		numerator_ -= denominator_;
		return *this;
	}
	Fraction operator -- (int)
	{
		Fraction prev = *this;
		--(*this);
		return prev;
	}
};

void function(int a, int b) // функция проверки ввода чисел
{
	if ((a <= 0) || (b <= 0))
	{
		throw std::runtime_error("Вы ввели не натуральное число. Выполнение этого задания невозможно");
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int num = 0; 
	int den = 0; 
	try
	{
		std::cout << "Введите числитель дроби 1: ";
		std::cin >> num;
		std::cout << "Введите знаменатель дроби 1: ";
		std::cin >> den;
		function(num, den);
		Fraction f1(num, den);
		std::cout << "Введите числитель дроби 2: ";
		std::cin >> num;
		std::cout << "Введите знаменатель дроби 2: ";
		std::cin >> den;
		function(num, den);
		Fraction f2(num, den);

		Fraction f3 = (f1 + f2).LCD();
		std::cout << f1.getNum() << "/" << f1.getDen() << " + " << f2.getNum() << "/" << f2.getDen() << " = " << f3.getNum() << "/" << f3.getDen() << '\n';
		Fraction f4 = (f1 - f2).LCD();
		std::cout << f1.getNum() << "/" << f1.getDen() << " - " << f2.getNum() << "/" << f2.getDen() << " = " << f4.getNum() << "/" << f4.getDen() << '\n';
		Fraction f5 = (f1 * f2).LCD();
		std::cout << f1.getNum() << "/" << f1.getDen() << " * " << f2.getNum() << "/" << f2.getDen() << " = " << f5.getNum() << "/" << f5.getDen() << '\n';
		Fraction f6 = (f1 / f2).LCD();
		std::cout << f1.getNum() << "/" << f1.getDen() << " / " << f2.getNum() << "/" << f2.getDen() << " = " << f6.getNum() << "/" << f6.getDen() << '\n';
		Fraction f7 = (-f1).LCD();
		std::cout << f1.getNum() << "/" << f1.getDen() << " unary minus" << " = " << f7.getNum() << "/" << f7.getDen() << '\n';
	
		std::cout << "++" << f1.getNum() << "/" << f1.getDen() << " * " << f2.getNum() << "/" << f2.getDen() << " = ";
		Fraction f8 = (++f1 * f2).LCD();
		std::cout << f8.getNum() << "/" << f8.getDen() << '\n';
		std::cout << "Значение дроби 1 = " << f1.getNum() << "/" << f1.getDen() << '\n';

		std::cout << "--" << f1.getNum() << "/" << f1.getDen() << " * " << f2.getNum() << "/" << f2.getDen() << " = ";
		Fraction f9 = (f1-- * f2).LCD();
		std::cout << f9.getNum() << "/" << f9.getDen() << '\n';
		std::cout << "Значение дроби 1 = " << f1.getNum() << "/" << f1.getDen() << '\n';
	}
	catch (const std::runtime_error& bad_number)
	{
		std::cout << bad_number.what() << std::endl;
	}
	return 0;
}