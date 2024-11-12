#include <iostream>
#include <string>
#include <vector>

#define ll long long

class BankAccount {
private:
	ll balance;

public:
	BankAccount() : balance(0) { };
	BankAccount(ll base) : balance(base) { };

	void deposit(ll add) {
		balance += add;
		std::cout << "Saldo Bertambah " << ubahFormat(add) << '\n';
		getBalance();
	}

	void withdraw(ll sub) {	
		if (balance < sub) {
			std::cout << "Saldo Habis! \n";
			balance = 0;
			return;
		}
		balance -= sub;
		std::cout << "Saldo Berkurang " << ubahFormat(sub) << '\n';
		getBalance();
	}

	void getBalance() {
		std::string saldo = ubahFormat(balance);	
		std::cout << "Saldo Sekarang Adalah : " << saldo << "\n\n";
	}

	std::string ubahFormat(ll balance) {
		std::string saldo = std::to_string(balance);
		for (int i = saldo.length() - 1, count = 1; i >= 0; i--, count++) {
			if (count % 3 == 0) {
				if (i == 0) break;
				saldo.insert(saldo.begin() + i, '.');
			}
		}
		saldo.insert(saldo.begin(), ' ');
		saldo.insert(saldo.begin(), '.');
		saldo.insert(saldo.begin(), 'p');
		saldo.insert(saldo.begin(), 'R');
		return saldo;
	}

};

int main() {
	BankAccount BCA;	
	bool lanjut = true;
	std::vector<std::string> q = {
		"Deposit Uang ke Rekening",
		"Ambil Uang dari Rekening",
		"Cek Saldo Rekening"
	};

	while (lanjut) {
		std::cout << "Pilih Menu ATM : \n";
		for (int i = 0, len = q.size(); i < len; i++) {
			std::cout << i + 1 << ". " << q[i] << '\n';
		}
		std::cout << "Pilih Menu : ";
		int pilih;
		do {
			std::cin >> pilih;
			if (pilih != 1 && pilih != 2 && pilih != 3) {
				std::cout << "Nilai Salah \nMasukkan Kembali Nilai : ";
			}
		} while (pilih != 1 && pilih != 2 && pilih != 3);

		std::cout << '\n';
		int uang;

		switch (pilih) {
		case(1):
			std::cout << "Jumlah Uang Deposit : ";
			std::cin >> uang;
			BCA.deposit(uang);
			break;

		case(2):
			std::cout << "Jumlah Tarik Uang : ";
			std::cin >> uang;
			BCA.withdraw(uang);
			break;

		case(3):
			BCA.getBalance();
			break;

		}

		std::cout << "Lanjut ? (y/n) : " ;
		char lanjutMenu;
		do {
			std::cin >> lanjutMenu;
			if (toupper(lanjutMenu) != 'Y' && toupper(lanjutMenu) != 'N') {
				std::cout << "Masukkan Angka yang Benar!\n";
			}
		} while (toupper(lanjutMenu) != 'Y' && toupper(lanjutMenu) != 'N');

		if (toupper(lanjutMenu) == 'N') lanjut = false;
	}
	
	return 0;
}
