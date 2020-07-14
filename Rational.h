#pragma once
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

template<class T>
class Rational
{
private:
	T P;
	T Q;
	T GCD;

	Rational AddRationalNumbers(Rational a, Rational b) {
		Rational tmp(a.GetP() * b.GetQ() + b.GetP() * a.GetQ(), a.GetQ() * b.GetQ());
		ConvertToRedused();
		return tmp;
	}

	Rational DiffRationalNumbers(Rational a, Rational b) {
		Rational tmp(a.GetP() * b.GetQ() - b.GetP() * a.GetQ(), a.GetQ() * b.GetQ());
		ConvertToRedused();
		return tmp;
	}

	Rational ProdRationalNumbers(Rational a, Rational b) {
		Rational tmp(a.GetP() * b.GetP(), a.GetQ() * b.GetQ());
		ConvertToRedused();
		return tmp;
	}

	Rational DivRationalNumbers(Rational a, Rational b) {
		Rational tmp(a.GetP() * b.GetQ(), a.GetQ() * b.GetP());
		ConvertToRedused();
		return tmp;
	}

	bool AreRationalNumbersEqual(Rational a, Rational b) {
		return (a.GetRationalValue() == b.GetRationalValue()) ? true : false;
	}

	T FindGCD(T P, T Q) {
		assert(Q != 0);
		if (P == 0)
			return Q;

		if (P == Q)
			return Q;

		if (Q > P)
			return FindGCD(P, Q - P);
		return FindGCD(P - Q, Q);
	}

public:
	Rational() { }

	Rational(T defP, T defQ) {
		assert(defQ != 0);
		P = defP;
		Q = defQ;
	}

	Rational(const Rational &object) : P(object.P), Q(object.Q) {
		cout << "copy constructor" << endl;
	}


	T GetP() {
		return P;
	}

	void SetP(T newP) {
		P = newP;
	}

	T GetQ() {
		return Q;
	}

	void SetQ(T newQ) {
		Q = newQ;
	}

	void ConvertToRedused() {
		GCD = FindGCD(P, Q);
		if (GCD == 1)
			return;
		P = P / GCD;
		Q = Q / GCD;
		return ConvertToRedused();
	}

	T FindNewGCD() {
		return FindGCD(this->GetP(), this->GetQ());
	}

	Rational operator+(const Rational& other) {
		return AddRationalNumbers(*this, other);
	}

	Rational operator-(const Rational& other) {
		return DiffRationalNumbers(*this, other);
	}

	Rational operator*(const Rational& other) {
		return ProdRationalNumbers(*this, other);
	}

	Rational operator/(const Rational& other) {
		return DivRationalNumbers(*this, other);
	}

	bool operator==(const Rational& other) {
		return AreRationalNumbersEqual(*this, other);
	}

	char GetRationalRatio(Rational a, Rational b) {
		if (a.GetRationalValue() > b.GetRationalValue())
			return '>';
		else if (a.GetRationalValue() < b.GetRationalValue())
			return '<';
		else
			return '=';
	}

	float GetRationalValue() {
		assert(Q != 0);
		return (float)P / (float)Q;
	}

	string Print() {
		string tmp = "";
		tmp += "[";
		tmp += to_string(P);
		tmp += "/";
		tmp += to_string(Q);
		tmp += "]";
		return tmp;
	}
};