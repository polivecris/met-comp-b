# Passo 1. Compilar os programas
gcc FogueteEuler.c -o FogEuler -lm
gcc FogueteRK2.c -o FogRK2 -lm
gcc FogueteRK4.c -o FogRK4 -lm

# Passo 2. Rodar os programas
./FogEuler
./FogRK2
./FogRK4

# Passo 3. Gerar gráficos de interesse
gnuplot load 'Rocket.gnu'

