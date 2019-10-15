#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

Rational::Rational() {
   this->numerator = 0;
   this->denominator = 1;
}

Rational::Rational(int numerator) {
   this->numerator = numerator;
   this->denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
   this->numerator = numerator;
   this->denominator = denominator;
}

// Implement Rational class member functions here
const Rational Rational::add(const Rational &r) const {
   int resultNumerator = (numerator * r.denominator) + (denominator * r.numerator);
   int resultDenominator = denominator * r.denominator;
   return Rational(resultNumerator,resultDenominator);
}

const Rational Rational::subtract(const Rational &r) const {
   int resultNumerator = (numerator * r.denominator) - (denominator * r.numerator);
   int resultDenominator = denominator * r.denominator;
   return Rational(resultNumerator,resultDenominator);
}

const Rational Rational::multiply(const Rational &r) const {
   int resultNumerator = numerator * r.numerator;
   int resultDenominator = denominator * r.denominator;
   return Rational(resultNumerator,resultDenominator);
}
const Rational Rational::divide(const Rational &r) const {
   int resultNumerator =  numerator * r.denominator;
   int resultDenominator = r.numerator *  denominator;
   return Rational(resultNumerator,resultDenominator);
}

void Rational::display() const {
   cout << numerator << " / " << denominator;
}

void Rational::simplify() {
   int cd = gcd(numerator, denominator);
   numerator /= cd;
   denominator /= cd;
}

int Rational::gcd(int a, int b) const {
   int temp;
   while(b != 0) {
      temp = b;
      b = a % b;
      a = temp;
   }
   return a;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

