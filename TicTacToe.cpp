#include <iostream>

using namespace std;

char papan[3][3];
char pemain;

void inisialisasiPapan() {
    char angka = '1';
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            papan[i][j] = angka++;
        }
    }
}

void tampilkanPapan(){
    cout << "Papan Tic-Tac-Toe:\n";
    for(int i = 0; i < 3; i++){
        cout << " ";
        for(int j = 0; j < 3; j++){
            cout << papan[i][j];
            if(j < 2) cout << " | ";
        }
        if(i < 2) cout << "\n---|---|---\n";
    }
    cout << endl;
}

void gantiPemain(){
    pemain = (pemain == 'X') ? 'O' : 'X';
}

bool tempatTersedia(int posisi){
    int baris = (posisi - 1) / 3;
    int kolom = (posisi - 1) % 3;
    return (papan[baris][kolom] != 'X' && papan[baris][kolom] != 'O');
}

void tandaiPapan(int posisi){
    int baris = (posisi - 1) / 3;
    int kolom = (posisi - 1) % 3;
    papan[baris][kolom] = pemain;
}

bool cekKemenangan() {
    
    for(int i = 0; i < 3; i++){
        if(papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2]) return true;
        if(papan[0][i] == papan[1][i] && papan[1][i] == papan[2][i]) return true;
    }
    
    if(papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2]) return true;
    if(papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0]) return true;
    return false;
}

bool cekSeri(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(papan[i][j] != 'X' && papan[i][j] != 'O') return false;
        }
    }
    return true;
}

void gamenya(){
    int posisi;
    bool menang = false;
    
    inisialisasiPapan();
    pemain = 'X';
    
    while (!menang && !cekSeri()){
        tampilkanPapan();
        cout << "Pemain " << pemain << ", pilih posisi (1 - 9): ";
        cin >> posisi;
        
        if (cin.fail() || posisi < 1 || posisi > 9 || !tempatTersedia(posisi)){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Posisi tidak valid. Coba lagi.\n";
        } else{
            tandaiPapan(posisi);
            menang = cekKemenangan();
            
            if(!menang)
                gantiPemain();
        }
    }
    
    tampilkanPapan();
    
    if (menang)
        cout << "Selamat! Pemain " << pemain << " menang!!!\n";
    else
        cout << " -- Permainan seri. --\n";
}

int main(){
    char n;
    bool selesai = false;
    while(!selesai){
        gamenya();
        cout << endl;
        cout << "Ulangi? (y/n): ";
        cin >> n;
        if(n == 'n') selesai = true;
    }
    cout << "\n--- Terima kasih ---\n";
    return 0;
}
