#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
class StaticVector
{
private:
	int length;
	int maxLength = 255;
	T vector[255];

	StaticVector AddVectors(StaticVector a, StaticVector b) {
		StaticVector temp;
		int maxLength = max(a.GetLength(), b.GetLength());

		temp.SetLength(maxLength);
		T *vectorATemp = new T[a.GetLength()];
		T *vectorBTemp = new T[b.GetLength()];

		a.GetVector(vectorATemp, a.GetLength());
		b.GetVector(vectorBTemp, b.GetLength());

		if (a.GetLength() != maxLength)
		{
			for (int i = 0; i < a.GetLength(); i++) {
				temp.FillVectorByIndex(i, vectorATemp[i] + vectorBTemp[i]);
			}
			for (int i = a.GetLength(); i < maxLength; i++)
			{
				temp.FillVectorByIndex(i, vectorBTemp[i]);
			}
		}
		else
		{
			for (int i = 0; i < b.GetLength(); i++) {
				temp.FillVectorByIndex(i, vectorATemp[i] + vectorBTemp[i]);
			}
			for (int i = b.GetLength(); i < maxLength; i++)
			{
				temp.FillVectorByIndex(i, vectorATemp[i]);
			}

		}

		delete[] vectorATemp;
		delete[] vectorBTemp;
		return temp;
	}

	StaticVector DifferenceVectors(StaticVector a, StaticVector b) {
		StaticVector temp;
		int maxLength = max(a.GetLength(), b.GetLength());

		temp.SetLength(maxLength);
		T *vectorATemp = new T[a.GetLength()];
		T *vectorBTemp = new T[b.GetLength()];

		a.GetVector(vectorATemp, a.GetLength());
		b.GetVector(vectorBTemp, b.GetLength());

		if (a.GetLength() != maxLength)
		{
			for (int i = 0; i < a.GetLength(); i++) {
				temp.FillVectorByIndex(i, vectorATemp[i] - vectorBTemp[i]);
			}
			for (int i = a.GetLength(); i < maxLength; i++)
			{
				temp.FillVectorByIndex(i, 0 - vectorBTemp[i]);
			}
		}
		else
		{
			for (int i = 0; i < b.GetLength(); i++) {
				temp.FillVectorByIndex(i, vectorATemp[i] - vectorBTemp[i]);
			}
			for (int i = b.GetLength(); i < maxLength; i++)
			{
				temp.FillVectorByIndex(i, vectorATemp[i]);
			}

		}

		delete[] vectorATemp;
		delete[] vectorBTemp;
		return temp;
	}


	T ProductVectors(StaticVector a, StaticVector b) {
		T product = 0;
		int maxLength = max(a.GetLength(), b.GetLength());

		T *vectorATemp = new T[a.GetLength()];
		T *vectorBTemp = new T[b.GetLength()];

		a.GetVector(vectorATemp, a.GetLength());
		b.GetVector(vectorBTemp, b.GetLength());

		if (a.GetLength() != maxLength)
		{
			for (int i = 0; i < a.GetLength(); i++) {
				product += a.GetVectorValueByIndex(i) * b.GetVectorValueByIndex(i);
			}
		}
		else
		{
			for (int i = 0; i < b.GetLength(); i++) {
				product += a.GetVectorValueByIndex(i) * b.GetVectorValueByIndex(i);
			}
		}

		delete[] vectorATemp;
		delete[] vectorBTemp;
		return product;
	}

	int max(int a, int b) {
		return (a < b) ? b : a;
	}

public:
	StaticVector() {
		length = 0;
	}

	StaticVector(T initializeValue) {
		for (int i = 0; i < maxLength; i++) {
			vector[i] = initializeValue;
		}
	}

	StaticVector(const StaticVector &object) : length(object.length), maxLength(object.maxLength) {
		cout << "copy constructor" << endl;
		for (int i = 0; i < maxLength; i++)
		{
			vector[i] = object.vector[i];
		}
	}

	void SetLength(int len) {
		if (len >= 0 && len < maxLength)
			length = len;
		else
			length = maxLength - 1;
	}

	int GetLength() {
		return length;
	}

	int GetMaxLength() {
		return maxLength;
	}

	void FillVector() {
		assert(length > 0 && length < maxLength);
		for (int i = 0; i < length; i++) {
			cin >> vector[i];
		}
	}

	void FillVectorByIndex(int index, T value) {
		assert(index >= 0 && index < maxLength);
		vector[index] = value;
	}

	void PrintVector() {
		assert(length >= 0 && length < maxLength);
		for (int i = 0; i < length; i++) {
			cout << vector[i] << " ";
		}
		cout << endl;
	}

	void GetVector(T * temp, int len) {
		assert(len == length);
		for (int i = 0; i < length; i++) {
			temp[i] = vector[i];
		}
	}

	T GetVectorValueByIndex(int index) {
		assert(index >= 0 && index < length);
		return vector[index];
	}


	StaticVector operator+(const StaticVector& other) {
		return AddVectors(*this, other);
	}

	StaticVector operator-(const StaticVector& other) {
		return DifferenceVectors(*this, other);
	}

	T operator*(const StaticVector& other) {
		return ProductVectors(*this, other);
	}

	~StaticVector() { }
};
