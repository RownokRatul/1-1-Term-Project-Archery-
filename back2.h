Image *TextureImageback2= loadTexture("lvl2.bmp");

int width2 = TextureImageback2->sizeX;
int height2 = TextureImageback2->sizeY;
int nPixels2 = width2 * height2;
//int *rgPixels = new int[nPixels2];
unsigned char *bgraBuffer2 = new unsigned char[nPixels2*4];

void load_back2 () {

    int i,j,k;
    int posBgr = 0;
    int posBgra = 0;
    int pi = 0;
    for (int i = 0; i < nPixels2; i++){
        pi = 0;
        pi |= TextureImageback2->data[posBgr];
        pi &= 0x000000FF;
        pi = (pi << 8)|TextureImageback2->data[posBgr+1];
        pi &= 0x0000FFFF;
        pi = (pi << 8)|TextureImageback2->data[posBgr+2];
        pi &= 0x00FFFFFF;
        //Sets the alpha buffer value.


        bgraBuffer2[posBgra] = TextureImageback2->data[posBgr];          //This is the buffer value of R.
        bgraBuffer2[posBgra + 1] = TextureImageback2->data[posBgr + 1];  //This is the buffer value of G.
        bgraBuffer2[posBgra + 2] = TextureImageback2->data[posBgr+2];  //This is the buffer value of B.
        bgraBuffer2[posBgra + 3] = 255;
        //bgraBuffer2[posBgra + 3] = 0;
        posBgr += 3;
        posBgra += 4;
    }


}
void draw_back2(int x, int y) {
    glRasterPos2f(x, y);
    glDrawPixels(TextureImageback2->sizeX, TextureImageback2->sizeY, GL_RGBA, GL_UNSIGNED_BYTE, bgraBuffer2);
}

