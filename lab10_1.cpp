#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){
	double loan, interestRate, PPY;

	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> interestRate;
	cout << "Enter amount you can pay per year: ";
	cin >> PPY;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#";
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect

	cout << fixed << setprecision(2);

	double Interest, Total, Payment, PrevBalance = loan, NewBalance = loan;

	for(int year = 1; NewBalance != 0 && !(NewBalance < 0); year++){

		cout << setw(13) << left << year;

		if(year == 1){
			cout << setw(13) << left << PrevBalance;
		}else{
			cout << setw(13) << left << NewBalance;
		}

		Interest = (interestRate/100.0)*NewBalance;
		cout << setw(13) << left << Interest;

		Total = NewBalance + ((interestRate/100.0)*NewBalance);
		cout << setw(13) << left << Total;

		Payment = PPY;
		if( Payment > Total) break;
		cout << setw(13) << left << Payment;

        NewBalance = Total - Payment;
		cout << setw(13) << left << NewBalance;
		cout << "\n";
	}
	cout << setw(13) << left << NewBalance + ((interestRate/100.0)*NewBalance);
	cout << setw(13) << left << 0.00;

	return 0;
}
