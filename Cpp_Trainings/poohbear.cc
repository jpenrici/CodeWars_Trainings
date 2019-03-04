/*
CODEWARS
https://www.codewars.com/kata/59a9735a485a4d807f00008a

"Esoteric Language: 'Poohbear' Interpreter"
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

// Solução
const char *poohbear (const char* sourcecode) {
    
    if (strlen(sourcecode) == 0) return "";

    // Checar quantidade de saídas (P/N)
    int n = 0;
    for (int i = 0; i < strlen(sourcecode); ++i)
        if (sourcecode[i] == 'P' || sourcecode[i] == 'N') n++;

    // Alocar células vazias
    int *vector = new int[n];
    for (int i = 0; i < n; ++i) vector[i] = 0;

    // Percorrer "string" sourcecode
    bool loop = false;
    std::string outString = "";
    int cell(0), copyValue(0), count(0), last(0);

    while (count < strlen(sourcecode))
    {
        // printf("[%c] count: %i cell: %i  value: %i  copy: %i\n",
        //  sourcecode[count], count, cell, vector[cell], copyValue);
        switch (sourcecode[count]) {
            case '>': // Move o índice da célula para direita em 1 posição
                cell = cell + 1;
                break;
            case '<': // Move o índice da célula para esquerda em 1 posição
                cell = cell - 1;
                break;              
            case '+':  // Adiciona 1 ao valor da célula atual
                vector[cell] = (vector[cell] + 1) % 256;
                break;
            case '-':  // Subtraí 1 ao valor da célula atual
                vector[cell] = (vector[cell] - 1) % 256;
                break;
            case 'c':  // Copia o valor da célula atual na váriavel "Cópia"
                copyValue = vector[cell];
                break;
            case 'p':  // Cola o valor copiado na célula atual
                vector[cell] = copyValue;
                break;
            case 'N':  // Adiciona na string de saída o valor inteiro da célula atual
                outString = outString + std::to_string (int(vector[cell]));
                // printf(" (%i)\n", int(vector[cell]));
                break;
            case 'P':  // Adiciona na string de saída o valor ascii da célula atual
                outString = outString + char(vector[cell]);
                // printf(" (%c)\n", char(vector[cell]));
                break;                  
            case 'T':  // Multiplica o valor da célula atual por 2
                vector[cell] = (vector[cell] * 2) % 256;
                break;
            case 'Q':  // Multiplica o valor da célula atual por ela mesma
                vector[cell] = (vector[cell] * vector[cell]) % 256;
                ;break;
            case 'U':  // Tira raiz quadrada do valor da célula atual
                vector[cell] = int(sqrt(vector[cell])) % 256;
                break;
            case 'L':  // Adiciona 2 ao valor da célula atual
                vector[cell] = (vector[cell] + 2) % 256;
                break;
            case 'I':  // Subtraí 2 ao valor da célula atual
                vector[cell] = (vector[cell] - 2) % 256;
                break;
            case 'V':  // Divide a célula atual por 2
                vector[cell] = int(vector[cell] / 2) % 256;
                break;
            case 'A':  // Adiciona o valor copiado à célula atual
                vector[cell] = (vector[cell] + copyValue) % 256;
                break;
            case 'B':  // Subtraí o valor copiado à célula atual
                vector[cell] = (vector[cell] - copyValue) % 256;
                break;
            case 'Y':  // Multiplica o valor copiado à célula atual
                vector[cell] = (vector[cell] * copyValue) % 256;
                break;
            case 'D':  // Divide o valor copiado à célula atual
                vector[cell] = (int(vector[cell] / copyValue)) % 256;
                break;
            case 'W':  // While loop
                last = count;
                if (vector[cell] != 0)
                    loop = true;
                if (vector[cell] == 0){
                    for (int i = count; i < strlen(sourcecode); ++i)
                        if (sourcecode[i] == 'E'){
                            count = i;
                            break;
                        }
                }
                break;
            case 'E':  // Fecha o loop
                if (loop == true){
                    loop = false;
                    count = last - 1;
                }
                break;          
        }
        count = count + 1;
    }
    
    // Converte std::string para char*
    char* output = new char[outString.size() + 1];
    std::copy(outString.begin(), outString.end(), output);
    output[outString.size()] = '\0';

    delete []vector;

    return output;
}

// Testes
void shouldBe (const char *input, const char *expected) {
  const char *actual = poohbear (input);
  int ok = actual && !strcmp (actual, expected);
  printf("input: %s\n", input);
  printf("actual: %s\nexpected: %s\n", actual, expected);
  // if (!ok) printf ("poohbear (\"%s\")\n", input);
  if (ok) printf("True\n");
  else printf("False\n");
}

int main() {

    // Simple Tests
    shouldBe ("", "");
    shouldBe ("N", "0");
    shouldBe ("N+N", "01");
    shouldBe ("LTTLN", "10");
    shouldBe ("LTTLQN", "100");
    shouldBe ("LQQT+P", "!");
    shouldBe ("LQTcQAP>pQBBTAI-PA-PPL+P<BVPAL+T+P>PL+PBLPBP<DLLLT+P", "Hello World!");
    shouldBe ("LQQT+P+P+P+P+P+P", "!\"#$%&");
    shouldBe ("+c BANANA", "12");

    // https://esolangs.org/wiki/Poohbear
    shouldBe ("+LTQTP>LL+TQ+P>LLT-c<APP>IIc<AP>I->+LLT+TTP<+LLTLc>BP>+LQQLLLP<<<PL+PIIIPIIIIP>>>>LLQT+P", "Hello, World!");

    // Loops
    shouldBe ("+W+EN", "0");
    shouldBe ("+LTQII>+WN<P>+E", "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 153 154 155 156 157 158 159 160 161 162 163 164 165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 180 181 182 183 184 185 186 187 188 189 190 191 192 193 194 195 196 197 198 199 200 201 202 203 204 205 206 207 208 209 210 211 212 213 214 215 216 217 218 219 220 221 222 223 224 225 226 227 228 229 230 231 232 233 234 235 236 237 238 239 240 241 242 243 244 245 246 247 248 249 250 251 252 253 254 255 ");
    shouldBe ("cW>LQQT+P<pE", "");
    shouldBe ("+W>LQQT+P<-E", "!");
    shouldBe ("LILcABNBpYDYYYYLLL+P-+W-EQNW-ELLQUTTTT+P", "2'0A");

    return 0;
};
