Membuat program untuk teller atau admin bank untuk 
mengelola antrian dan transaksi nasabah dalam suatu bank.

Sistem administrasi teller ini mengimplementasikan beberapa struktur data, di antaranya Linked list yang digunakan untuk struktur dalam Queue dan Stack sehingga lebih optimal
Selanjutnya ada Queue untuk menyimpan data sementara dari nasabah yang sedang melakukan antrian layanan teller, dimana enqueue akan dilakukan ketika teller memasukkan data nasabah, dequeue dilakukan setelah nasabah dilayani, dan print queue
dilakukan untuk mengecek jumlah antrian nasabah.
Terakhir ada Stack untuk menyimpan riwayat nasabah yang telah melakukan transaksi teller. Push stack dilakukan tepat setelah dequeue, dimana data nasabah yang telah selesai dilayani akan di push ke dalam stack sebagai riwayat pelayanan.
