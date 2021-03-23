Image *TextureImageback3= loadTexture("lvl1.bmp");

int width3 = TextureImageback3->sizeX;
int height3 = TextureImageback3->sizeY;
int nPixels3 = width3 * height3;
//int *rgPixels = new int[nPixels3];
unsigned char *bgraBuffer3 = new unsigned char[nPixels3*4];

void load_back3 () {

    int i,j,k;
    int posBgr = 0;
    int posBgra = 0;
    int pi = 0;
    for (int i = 0; i < nPixels3; i++){
        pi = 0;
        pi |= TextureImageback3->data[posBgr];
        pi &= 0x000000FF;
        pi = (pi << 8)|TextureImageback3->data[posBgr+1];
        pi &= 0x0000FFFF;
        pi = (pi << 8)|TextureImageback3->data[posBgr+2];
        pi &= 0x00FFFFFF;
        //Sets the alpha buffer value.


        bgraBuffer3[posBgra] = TextureImageback3->data[posBgr];          //This is the buffer value of R.
        bgraBuffer3[posBgra + 1] = TextureImageback3->data[posBgr + 1];  //This is the buffer value of G.
        bgraBuffer3[posBgra + 2] = TextureImageback3->data[posBgr+2];  //This is the buffer value of B.
        bgraBuffer3[posBgra + 3] = 255;
        //bgraBuffer3[posBgra + 3] = 0;
        posBgr += 3;
        posBgra += 4;
    }


}
void draw_back3(int x, int y) {
    glRasterPos2f(x, y);
    glDrawPixels(TextureImageback3->sizeX, TextureImageback3->sizeY, GL_RGBA, GL_UNSIGNED_BYTE, bgraBuffer3);
}

