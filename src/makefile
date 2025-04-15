#見返すとき用に機能を横に記載
CC = gcc #コンパイラの指定
CFLAGS_LDFLAGS = 'sdl-config --cflags --libs' #SDLヘッダ用フラグ, SDLリンク用フラグ

TARGET = main #出力ファイル名
SRCS = main.c #ソースファイル名

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS_LDFLAGS)

clean:
	rm -f $(TARGET)