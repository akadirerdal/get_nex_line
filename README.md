# get_next_line

*This project has been created as part of the 42 curriculum by
aberdal.*

## Description

`get_next_line`, verilen bir **file descriptor (fd)** üzerinden dosyayı
**satır satır okuyan** bir C fonksiyonudur.

Fonksiyon her çağrıldığında dosyadan **bir sonraki satırı** döndürür.
Satır sonu karakteri (`\n`) varsa dönen string içinde bulunur. Dosya
sonuna gelindiğinde veya hata oluştuğunda fonksiyon `NULL` döndürür.

Bu proje aşağıdaki konuları öğretmeyi amaçlar:

-   Static değişken kullanımı
-   File descriptor ile dosya okuma
-   Dinamik bellek yönetimi
-   Buffer mantığı
-   Satır bazlı veri işleme

------------------------------------------------------------------------

## Prototype

``` c
char *get_next_line(int fd);
```

### Parametre

  Parametre   Açıklama
  ----------- ------------------------------------------
  `fd`        Okunacak dosyanın file descriptor değeri

### Return

  Değer      Açıklama
  ---------- --------------------------------------
  `char *`   Okunan satır
  `NULL`     Dosya bittiğinde veya hata olduğunda

------------------------------------------------------------------------

## Allowed Functions

Projede kullanılmasına izin verilen fonksiyonlar:

    read
    malloc
    free

Yasak olanlar:

    lseek
    global variables
    libft

------------------------------------------------------------------------

## Compilation

Projeyi aşağıdaki şekilde compile edebilirsiniz:

``` bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

`BUFFER_SIZE`, `read()` fonksiyonunun her seferinde okuyacağı byte
miktarını belirler.

------------------------------------------------------------------------

## Usage Example

``` c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
}
```

------------------------------------------------------------------------

## Algorithm

Algoritmanın temel mantığı:

1.  `read()` ile dosyadan `BUFFER_SIZE` kadar veri okunur.
2.  Okunan veri static bir buffer içinde tutulur.
3.  Buffer içinde `\n` karakteri aranır.
4.  Eğer `\n` bulunursa satır ayrılır.
5.  Geri kalan veri buffer içinde saklanır.
6.  Satır return edilir.
7.  Dosya bittiğinde fonksiyon `NULL` döndürür.

Bu yöntem sayesinde dosya tamamen okunmadan satır satır işlenebilir.

------------------------------------------------------------------------

## File Structure

    get_next_line/
    │
    ├── makefile
    ├── get_next_line.c
    ├── get_next_line_utils.c
    ├── get_next_line.h
    └── README.md

------------------------------------------------------------------------

## Resources

Yararlı kaynaklar:

-   Linux `read()` man page
-   File descriptors (Unix I/O)
-   Static variables in C
-   Memory management (`malloc`, `free`)
-   Kodun işleyişini ve mantığını anlamak için ai.