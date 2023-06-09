// todo - pengulangan berdasarkan kondisi boolean
let counter;
do {
    console.log("Hello");
    confirm("Mau mengulang program?");
} while(counter);

// todo - pengulangan berdasarkan kondisi increament/decreament
let i = 0;
do {
    console.log(i);
    i++;
} while(i < 10);

// ? catatan = perbedaan while dengan do while adalah do while akan tetap menjalankan program sekali di awal meski kondisi awal bernilai false, sedangkan while hanya akan menjalankan program jika kondisi awal bernilai true.