# Passo 1. Compilar os programas que calculam erro final de h
gcc RocketFree_h.c -o RocketFree_h -lm
gcc RocketGrav_h.c -o RocketGrav_h -lm

# Passo 2. Rodar os programas
./RocketFree_h
./RocketGrav_h

# Passo 3. Apos escolha de h, compilar programas que calculam foguete
gcc RocketFree.c -o RocketFree -lm
gcc RocketGrav.c -o RocketGrav -lm
gcc RocketRes.c -o RocketRes -lm

# Passo 4. Rodar os programas
./RocketFree
./RocketGrav
./RocketRes

# Passo 5. Plotar os gráficos
echo "\n\n>>Passo 5. Plotar os graficos"
echo "\t>>Com o gnuplot use: load 'Rocket.gnu' que todos os graficos serao gerado.\n\n"
gnuplot
