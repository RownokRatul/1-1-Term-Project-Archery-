Image *TextureImageback= loadTexture("lvl1.bmp");

int width = TextureImageback->sizeX;
int height = TextureImageback->sizeY;
int nPixels = width * height;
//int *rgPixels = new int[nPixels];
unsigned char *bgraBuffer = new unsigned char[nPixels*4];

void load_back () {

    int i,j,k;
    int posBgr = 0;
    int posBgra = 0;
    int pi = 0;
    for (int i = 0; i < nPixels; i++){
        pi = 0;
        pi |= TextureImageback->data[posBgr];
        pi &= 0x000000FF;
        pi = (pi << 8)|TextureImageback->data[posBgr+1];
        pi &= 0x0000FFFF;
        pi = (pi << 8)|TextureImageback->data[posBgr+2];
        pi &= 0x00FFFFFF;
        //Sets the alpha buffer value.


        bgraBuffer[posBgra] = TextureImageback->data[posBgr];          //This is the buffer value of R.
        bgraBuffer[posBgra + 1] = TextureImageback->data[posBgr + 1];  //This is the buffer value of G.
        bgraBuffer[posBgra + 2] = TextureImageback->data[posBgr+2];  //This is the buffer value of B.
        bgraBuffer[posBgra + 3] = 255;
        //bgraBuffer[posBgra + 3] = 0;
        posBgr += 3;
        posBgra += 4;
    }


}
void draw_back(int x, int y) {
    glRasterPos2f(x, y);
    glDrawPixels(TextureImageback->sizeX, TextureImageback->sizeY, GL_RGBA, GL_UNSIGNED_BYTE, bgraBuffer);
}

