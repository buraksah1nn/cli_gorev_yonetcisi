# C++ CLI Task Manager (Görev Yöneticisi)

Bu proje, C++ çekirdek yeteneklerini (STL kütüphaneleri, bellek yönetimi ve veri kalıcılığı) pratik etmek amacıyla sıfırdan geliştirilmiş bir Komut Satırı (CLI) uygulamasıdır. Standart eğitim videolarındaki teorik bilgileri gerçek bir CRUD (Create, Read, Update, Delete) mimarisine dönüştürmeyi hedefler.

## Özellikler

- **Görev Ekleme:** Akıllı ID yönetimi ile çakışmaları önleyerek yeni görev oluşturma.
- **Dinamik Listeleme:** `std::vector` kullanılarak boyutu esnek, bellek dostu veri listeleme.
- **Durum Güncelleme:** Belirtilen ID'ye göre görevleri [X] (Tamamlandı) olarak işaretleme.
- **Güvenli Silme:** Doğrudan bellek adresleri (iterator) üzerinden verimli eleman silme (`erase`).
- **Kalıcı Veri Depolama (File I/O):** Program kapatıldığında veriler `missions.txt` dosyasına kaydedilir ve program açıldığında otomatik olarak geri yüklenir.
- **Tam Türkçe Desteği:** `<windows.h>` kütüphanesi ile Windows konsolunda Türkçe karakter (UTF-8/1254) uyumluluğu.

## Kullanılan Teknolojiler ve Kavramlar

- **Dil:** Modern C++
- **Veri Yapıları:** `struct`, `std::vector`
- **Dosya Yönetimi:** `<fstream>` (`ifstream` / `ofstream`)
- **Kontrol Akışı:** Gelişmiş `switch-case` yapıları, `cin.ignore()` ile girdi (buffer) temizliği.

## Geliştirme Sürecindeki Kazanımlar

Bu proje geliştirilirken hazır fonksiyonlara veya yüksek seviyeli kütüphanelere dayanmak yerine; 
* Girdi tamponunda (Input Buffer) kalan `\n` karakterlerinin okuma sırasındaki yan etkileri ve temizlenmesi, 
* Dosya sonu (EOF) okumalarındaki döngü hatalarının ayıklanması,
* Standart diziler yerine dinamik bellek tahsisi yapan Vektör yapısının davranışları deneyimlenmiştir.
