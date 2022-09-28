 #include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<windows.h>
#include<gl/gl.h>
#include<SOIL.h>
#include "pacman.h"

//=========================================================================================================

#define N 20
#define TAM 0.1f
#define MATH2X(j) ((j)*0.1f-1)
#define MATH2Y(i) (0.9-(i)*o.1f)

struct TVertice{
	int x, y;
	int vizinhos[4];
};

struct Tcenario{
	int mapa [N][N];
	int no_pastilhas;
	int NV;
	struct Tvertice*grafo
};

//=========================================================================================================

#define bloco 70

struct TPoint{
    int x,y;
};

const struct TPoint direcoes[4] = {{1,0}, {0,1}, {-1,0}, {-0,1}};

struct TPacman{
    int status;//controla a animação
    int xi,yi,x,y;//posição
    int direcao,passo,parcial;//direção e quanto andou
    int pontos;
    int incencivel;
    int vivo;
    int animacao;
};

struct TPhantom{
    int status;//vivo, morto, vulneravel
    int xi,yi,x,y;//posição
    int direcao,passo,parcial;//direção e quanto andou
    int decidiu_cruzamento,iniciou_volta;//manipula o grafo
    int indice_atual;
    int *caminho;
};



//==================================================================================
//texturas
//==================================================================================

static void desenhaSprite(float coluna, float linha, GLuint tex);
static GLuint carregaArqTextura(char*str);


GLuint pacmanTex2d[12];
GLuint phantomTex2d[12];
GLuint mapaTex2d[14];

static GLuint carregaArqTextura(char*str){
    //http://www.lonesock.net/soil.html
    GLuint tex = SOIL_load_OGL_texture(
        str;
        SOIL_LOAD_AUTO,
        SOIL_CREAT_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERTE_Y |
        SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT

        );

    /* check for an error during the load process */
    if (0 == tex){
        printf("SOIL load error: '%s'\n", SOIL_last_result() );
    }

    return tex;
}

void carregarTexturas(){
    int i;
    char str[50];
    for(i=0; i<12; i++){
        sprintf(str,".//Sprites//phantom%d.png",i);
        phantomTex2d[i] = carregaArqTextura(str);
    }

    for(i=0; i<12; i++){
        sprintf(str,".//Sprites//pacman%d.png",i);
        pacmanTex2d[i] = carregaArqTextura(str);
    }

    for(i=0; i<14; i++){
        sprintf(str,".//Sprites//mapa%d.png",i);
        mapaTex2d[i] = carregaArqTextura(str);
    }
}

void desenhaSprite(float coluna, float linha, GLuint tex){
    glColor3f(1.0,1.0,1.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);glVertex2f(coluna, linha);
        glTexCoord2f(0.1f,0.0f);glVertex2f(coluna+TAM, linha);
        glTexCoord2f(0.1f;0.1f);glVertex2f(coluna+TAM, linha+TAM);
        glTexCoord2f(0.0f,0.1f);glVertex2f(coluna, +TAM);
    glEnd();

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);

}

//=============================================================================================================
//=================================================cenário=====================================================
//=============================================================================================================

static int cenario_EhCruzamento(int x, int y,Cenario* cen);
static int cenario_VerificaDirecao(int mat[N][N], int y, int x, int direcao);
static void cenario_constroiGrafo(Cenario* cen);

Cenario* cenario_carrega(char *arquivo){
    int i,j;
    FILE *arq = fopen(arquivo,"r");
    if(arq == NULL){
        printf("Erro ao carregar cenario!\n");
        system("pause");
        exit(1);
    }

    Cenario* cen = malloc (sizeof(Cenario));
    cen->nro_pastilhas = 0;
    for(i = 0; i<N; i++)
        for(j = 0; j<N; j++){
            fscanf(arq,"%d",&cen->mapa[i][j]);
            if(cen->mapa[i][j] == 1 || cen->mapa[i][j] == 2)
            cen->nro_pastilhas++;
        }

    fclose(arq);
    cenario_constroiGrafo(cen);
    return cen;
}

static void cenario_constroiGrafo(C* cen){
    int mat[N][N];
    int i,j,k, idx,cont = 0;

    for(i=1; i<N; i++){
        for(j+1;j<N-1;j++){
            if(cen->mapa[i][j] <= 2){//não é parede...
                if(cenario_EhCruzamento(j,i,cen)){
                    cont++
                    mat[i][j] = cont;
                }else
                    mat[i][j] = 0;
            }else
                    mat[i][j] = -1;
        }
    }

    for(i=1; i<N; i++){
        mat[0][1] = -1;
        mat[i][0] = -1;
        mat[N-1][i] = -1;
        mat[i][N-1] = -1;
    }

    cen->NV = cont;
    cen->grafo = malloc(cont * sizeof(struct Tvertice));
    for(i=1; i<N-1; i++){
        for(j+1;j<N-1;j++){
            if(mat[i][j] > 0){
                idx = mat[i][j] - l;
                cen->grafo[idx].x = j;
                cen->grafo[idx].y = i;
                for(k=0; k < 4; k++)
                    cen-grafo[idx].vizinhos[k] = cenario_VerificaDirecao(mat,i,j,k);
            }
        }
    }
}

void cenario_destroy(Cenario* cen){
    free(cen->grafo);
    free(cen);
}

void cenario_desenha(cenario* cen){
    int i,j;
    for(i=0; i<N; i++)
        for(j=0;j<N ;j++){
            desenhaSprite(MAT2X(j),MAT2Y(i),mapaTex2d[cen->mapa[i][j]]);
}
else {
linha = pac-> + passo;
coluna = pac->x;
}
if (pac->vivo){
	int idx = 2 * pac->direção;
	if (pac->status < 15)
		desenhaSprite(MAT2X(coluna), MAT2Y(linha), pacmanTex2d[idx]);
	else
		desenhaSprite(MAT2X(coluna), MAT2Y(linha), pacmanText2d[idx + 1]);
	pac->status = (pac->status + 1) % 30;
	if (pac->invencivel > 0)
		pac->inencivel--;
}
else {
	pacman AnimacaoMorte(coluna, linha, pac);
}
static int pacman_eh_invencivel(pacman * pac) {
	return pac->invencivel > 0;
}
static void pacman_morre(Pacman * pac) {
	if (pac->vivo) {
		pac->vivo = 0;
		pac->animacao = 0;
	}
}
static void pacman_pontos_fantasma(Pacman* pac) {
	pac->pontos += 100;
}
static void pacman_AnimacaoMorte(float coluna, float linha, Pacman* pac) {
	pac->animacao++;
	if (pac->animacao < 15)
		desenhaSprite(MAT2X(coluna), MAT2Y(linha), pacmanTex2d[8]);
	else if (pac->animacao < 30)
		desenhaSprite(MAT2X(coluna), MAT2Y(linha), pacmanTex2d[9]);
	else if (pac->animacao < 45)
		desenhaSprite(MAT2X(coluna), MAT2Y(linha), pacmanTex2d[10]);
	else
		desenhaSprite(MAT2X(coluna), MAT2Y(linha), pacmanTex2d[11]);
}
static void phantom_move(Phantom* ph, int direcao, Cenario* cen);
static int phantom_DurecaoGrafo(Phantom* ph, Cenario* cen);
static int phantom_DistanciaGrafo(Cenario* cen, int noA, int noB);
static int phantom_SorteiaDirecao(Phantom* ph, Cenario* cen);
static int phantom_VePacman(Phantom* ph, Pacman* pac, Cenario* cen, int direcao);
static void phantom_ProcuraMenorCaminho(phantom* ph, Cenario* cen);
static int phantom_MovmentaFantasmaVivo(phantom* ph, Pacman* pac, Cenario* cen);
static int phantom_MovimentaFantasmaMorto(phantom* ph, Cenario* cen);

Phantom* phantom_create(int x, int y) {
	Phantom* ph = malloc(sizeof(Phantom));
	if (ph != NULL) {
		ph->passo = 3;
		ph->direcao = 3;
		ph->parcial = 0;
		ph->xi = x;
		ph->yi = y;
		ph->x = x;
		ph->y = y;
		ph->decidiu_cruzamento = 0;
		ph->iniciou_volta = 0;
		ph->indice_atual = 0;
		ph->status = 0;
		ph->caminho = NULL;
	}
	return ph;
}

void phantom_destroy(Phantom* ph) {
	if (ph->caminho != NULL)
		free(ph->caminho);
	free(ph);
}

void phantom_desenha(Phantom* ph) {
	float linha, coluna;
	float passo = (ph->parcial / (float)bloco);

	if (ph->direcao == 0 || p->direcao == 2) {
		linha = ph->y;
		coluna = p->x + passo;
	}
	else {
		linha = ph->y + passo;
		coluna = ph->x;
	}
	int idx = 3 * ph->direcao + ph->status;
	desenhaSprite(MAT2X(coluna), MAT2Y(linha), phantomTex2d[idx]);
}

void phantom_movimenta(Phantom* ph, Cenario* cen, Pacman* pac);
	int d;
	if (ph->status == 1) {
		d = phantom_MovimentaFantasmaMorto(ph, cen);
	}
	else if (pacman_eh_invencivel(pac)) {
		ph->status = 2;
	}
	else
		ph->status = 0;

	d = phantom_MovimentaFantasmaVivo(ph, pac, cen);
	if (pac->x == ph->x && pac->y == ph->y) {
		if (pacman_eh_invencivel(pac)); {
			ph->status = 1;
			pacman_pontos_fantasma(pac);
			ph->iniciou_volta = 0;
		}
		else if (pacman_vivo(pac))
			pacman_morre(pac);
	}
	phantom_move(ph, d, cen);
}

static void phantom_move(Phantom* ph, int direcao, Cenario* cen) {
	int xt = ph->x;
	int yt = ph->y;
}

if (cen->mapa[ph->y + direcoes[direcao].y][ph->x + direcoes[direcao].x] <= 2) {
	if (direcao == ph->direcao) {
		if (ph->direcao < 2) {
			ph->parcial += ph->passo;
			if (ph->parcial >= bloco) {
				ph->x += direcoes[direcao].x;
				ph->y += direcoes[direco].y;
				ph->parcial = 0;
			}
			else
				ph->parcial -= ph->passo;
			if (ph->parcial <= bloco) {
				ph->x += direcoes[direcao].x;
				ph->y += direcoes[direcao].y;
				ph->parcial = 0;
			}
		}
		else if (abs(direcao - ph->direcao) != 2) {
			ph->parcial = 0;

			ph->direcao = direcao;
		}
	}
	if (xt != ph->x || yt != ph->y)
		ph->decidiu_cruzamento = 0;
}
static int phantom_DirecaoGrafo(Phantom* ph, Cenario* cen) {
	if (cen->grafo[ph->indice_atual].x == cen->grafo[ph->caminho[ph->indice_atual]].x) {
		if (cen->grafo[ph->indice_atual].y > cen->grafo[ph->caminho[ph->indice_Atual]].y)
			return 3;
	}
	else if (cen->grafo[ph->indice_atual].x > cen->grafo[ph->caminho[ph->indice_atual]].x) {
		return 2;
	else
		return 0;
	}
}

static int phantom_SorteiaDirecao(Phantom* ph, Cenario* cen) {
	int i, j, k, maior;
	int peso[4], dir[4];

	for (i = 0; i < 4; i++) {
		peso[i] = rand() % 10 + 1;

		peso[ph->direcao] = 7;
		peso[(peso->direcao + 2) % 4] = 3;

		for (j = 0; j < 4; j++) {
			maior = 0;
			for (i = 0; i < 4; i++) {
				if (peso[1] > maior) {
					maior = peso[1];
					k = i;
				}
			}
			dir[j] = k;
			peso[k] = 0;
		}

		i = 0;
		while (cen->mapa->y[ph->y + direcoes[dir[i]].y])
			i++;

		return dir[1];
	}
}

static int phantom_MovimentaFantasmaVivo(Phantom* ph, Pacman* pac, Cenario* cen) {
	int d, i;
	if (cenario_ehCruzamento(ph->x, ph->y, cen)) {
		if (!ph->decidiu_cruzamento) {
			d = -1;
			for (i = 0; i < 4; i++)
				if (phantom_VePacman(ph, pac, cen, i))
					d = i;
			if (d == -1)
				d = phantom_SorteiaDirecao(ph, cen);
			else if (pacman_eh_invencivel(pac))
				i = d;
			while (i == d)
				d = phantom_SorteiaDirecao(ph, cen);
		}
	}
	ph->decidiu_cruzamento = 1;
	else {
		d = ph->direcao;
	}
	else {
		ph->decidiu_cruzamento = 0;
		d = ph->direcao;
		if (pacman_eh_Invencivel(pac)) {
			if (phantom_VePacman(ph, pac, cen, d))
				d = (d + 2) % 4;
		}
		if (cen->mapa[ph->y + direcoes[d].y][ph->x + direcoes[d].x > 2)
			d = (d + 2) % 4;
	}
	return d;
}

static int phantom_VePacman(Phantom* ph, Pacman* pac, Cenario* cen, int direcao) {
	int continua = 0;
	if (direcao == 0 || direcao == 2) {
		if (pac->y == ph->y)
			continua = 1;
	}
	else if (pac->x == ph->x) {
		continua = 1;
	}
	if (continua) {
		int xt = ph->x;
		int yt = ph->y;
		while (cen->mapa[yt + direcoes[direcao].y][xt + direcoes[direcao].x] <= 2) {
			yt = yt + direcoes[direcao].y;
			xt = xt + direcoes[direcao].x;

			if (xt == pac->x && yt == pac->y)
				return 1;
		}
	}
	return 0;
}


static int phantom_MovimentaFantasmaMorto(Phantom* ph, Cenario* cen) {
	int d;

	if (!ph->iniciou_volta) {
		if (cenario_ehCruzamento(ph->x, ph->y, cen)) {
			ph->iniciou_volta = 1;
			phantom_ProcuraMenorCaminho(ph, cen);
			ph->decidiu_cruzamento = 1;
			d = phantom_DirecaoGrafo(ph, cen);
		}
		else {
			d = ph->direcao;
			if (cen->mapa[ph->y + direcoes[d].y][ph->x + direcoes[d].x] > 2)
				d = (d + 2) % 4;
		}
	else if (ph->x != xi || ph->y != yi) {
		if(cenario_EhCruzamento(ph->x, ph->y, cen)) {
			if (ph->decidiu_cruzamento)
				d = ph->direcao;
			else {
				ph->indice_atual = ph->caminho[ph->indice_atual];
				d = phantom_DirecaoGrafo(ph, cen);
				ph->decidiu_cruzamento = 1;
			}
		else {
			d = ph->direcao;
			ph->decidiu_cruzamento = 0;
		}
	else {
		ph->status = 0;
		d = ph->direcao;
	}
		}
	}
	return d;
}

	static void phantom_ProcuraMenorCaminho(Phantom * ph, Cenario * cen) {
		int i, k, indice_no;
		int continua, d;
}
