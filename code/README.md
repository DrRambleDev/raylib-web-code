# How to compile to WebAssembly, JavaScript, and HTML and then to host online with Docker

griffinaustin9355@gmail.com

1. In VSCode, run 
```sh
emcc -o bacon.html main.cpp -Wall -std=c++14 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os -I. -I C:/raylib/raylib/src -I C:/raylib/raylib/src/external -L. -L C:/raylib/raylib/src -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 --shell-file C:/raylib/raylib/src/shell.html C:/raylib/raylib/src/web/libraylib.a -DPLATFORM_WEB -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]'-s EXPORTED_RUNTIME_METHODS=ccall
```
2. Switch to wsl by typing in wsl and hit enter
3. Generate docker-compose.yaml file by running sudo nano docker-compose.yaml
4. Put: 
```yaml
version: '3'
services:
  website:
    image: nginx:latest
    container_name: website
    volumes:
      - /mnt/c/code/src/html:/usr/share/nginx/html # NOTE: the first part is the file path, and the second part is the default location nginx looks for the html file
    ports:
      - 80:80
    restart: always
```

Formatting matters

then "Ctrl + X", "Y", and then hit enter

5. Go back to the directory that the html file is
6. Run docker-compose up -d --force-recreate
   Note: If it's your first time creating the .yaml file the --force-recreate tag isn't necessary
7. Then enjoy!

