#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	float loan, interest, PPY;

	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> interest;
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

	float PrevBalance = loan, NewBalance = PrevBalance, SumInterest, Total, Payment;

	for(int year = 1; NewBalance != 0 && !(NewBalance < 0); year++){

        Total = NewBalance + ((interest/100.0)*NewBalance);
        SumInterest = (interest/100.0)*NewBalance;
        Payment = PPY;

		cout << setw(13) << left << year;
		cout << setw(13) << left << PrevBalance;
		cout << setw(13) << left << SumInterest;
		cout << setw(13) << left << Total;
		if( Payment > NewBalance) break;
		cout << setw(13) << left << Payment;

        NewBalance = Total - Payment;
		cout << setw(13) << left << NewBalance;
        PrevBalance = NewBalance;

		cout << "\n";
	}
    Payment = Total;
	cout << setw(13) << left << Payment;
    cout << setw(13) << left << (NewBalance + SumInterest) - Payment;
    cout << "\n";
    
	return 0;
}
