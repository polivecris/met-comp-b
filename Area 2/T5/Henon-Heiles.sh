# Para compilar todos os programas
gcc Henon-Heiles_EC.c -o HH-EC -lm
./HH-EC

gcc Henon-Heiles_VV.c -o HH-VV -lm
./HH-VV

gcc Henon-Heiles_RK4.c -o HH-RK4 -lm
./HH-RK4

gcc Henon-Heiles_RK45.c -o HH-RK45 -lm
./HH-RK45

gcc Henon-Heiles_caos.c -o HHcaos -lm
./HHcaos

# As energias devem ser mudadas manualmente 
gcc poincare.c -o pncr -lm
./pncr



