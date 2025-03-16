#!/bin/bash

for i in {1..10}
do
    # Rastgele 100 sayı üret (-1000 ile 1000 arasında)
    ARG=$(seq -100000 100000 | sort -R | head -n 5000 | tr '\n' ' ')

    # Test başlığını yazdır
    echo "Test $i:"
    
    # push_swap'i çalıştır ve satır sayısını göster
    ./push_swap $ARG | ./checker_linux $ARG
    
    # Çıktılar arasına çizgi koy
    echo "----------------------"
done