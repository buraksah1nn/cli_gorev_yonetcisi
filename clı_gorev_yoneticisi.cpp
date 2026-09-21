#include <iostream>
#include <string> 
#include <vector>
#include <locale.h>
#include <fstream>
#include <windows.h>

using namespace std;

struct Task {
    int id;
    string description;
    bool is_completed;
};

int main() {
    SetConsoleOutputCP(1254);
    SetConsoleCP(1254);
    setlocale(LC_ALL, "Turkish");

    bool is_find = false;
    int automatic_id, secim, target_id;
    string push_description, bos;
    
    vector<Task> task_list;


    ifstream readFile("missions.txt");
    if (readFile.is_open()) {
        Task readMission;
        getline(readFile, bos); 
        while (readFile >> readMission.id) {
            readFile.ignore(); 
            getline(readFile, readMission.description);
            readFile >> readMission.is_completed;
            task_list.push_back(readMission);
        }
        
        readFile.close();
        cout << "Kayıtlı görevler dosyadan yüklendi.\n";
    }
    else {
        cout << "Kayıtlı dosya bulunamadı. Yeni liste oluşturuluyor.\n";
    }

    while (true) {
        cout << "\nYapmak istediğiniz işlemi seçiniz:\n1-Görev Listesini görüntüle\n2-Listeden görev sil\n3-Listeye Görev ekle\n4-Görev durumu güncelle\n0-Çıkış\n";
        cout << "Seçim: ";
        cin >> secim;
        cin.ignore(); 

        switch (secim) {
        case 3:
            cout << "Eklemek istediğiniz görevin bilgilerini giriniz:\n";
            getline(cin, push_description);
            
            if (task_list.empty()) {
                automatic_id = 1;
            } else {
                automatic_id = task_list.back().id + 1;
            }
            
            task_list.push_back({ automatic_id, push_description, false });
            cout << "Görev başarıyla eklendi.\n";
            break; 
            
        case 1:
            cout << "\n--- GÖREV LİSTESİ ---\n";
            for (const Task& task : task_list) {
                string status = task.is_completed ? "[X]" : "[ ]";
                cout << task.id << " | " << task.description << " " << status << "\n";
            }
            break;
            
        case 2:
            target_id = 0;
            is_find = false;
            cout << "Silinecek ID'yi giriniz:\n";
            cin >> target_id;
            cin.ignore();
            
            for (int i = 0; i < task_list.size(); i++) {
                if (task_list[i].id == target_id) {
                    is_find = true;
                    task_list.erase(task_list.begin() + i);
                    cout << "Görev başarıyla silindi.\n";
                    break;
                }
            }
            if (!is_find) {
                cout << "ID bulunamadı.\n";
            }
            break;
            
        case 4:
            target_id = 0;
            is_find = false;
            cout << "Tamamlanan görev ID'sini giriniz:\n";
            cin >> target_id;
            cin.ignore();
            
            for (int i = 0; i < task_list.size(); i++) {
                if (task_list[i].id == target_id) {
                    is_find = true;
                    task_list[i].is_completed = true;
                    cout << "Görev başarıyla güncellendi.\n";
                    break;
                }
            }
            if (!is_find) {
                cout << "ID bulunamadı.\n";
            }
            break;
            
        case 0: {
            ofstream enterFile("missions.txt");
            if (enterFile.is_open()) {
                enterFile << "Görev ID | Görev | Durum\n"; 
                for (const Task& task : task_list) {
                    enterFile << task.id << "\n";
                    enterFile << task.description << "\n";
                    enterFile << task.is_completed << "\n";
                }
                enterFile.close();
                cout << "Veriler dosyaya kaydedildi.\nÇıkış yapılıyor...\n";
            }
            else {
                cout << "HATA: Dosya oluşturulamadı.\n";
            }
            return 0;
        }
        default:
            cout << "Geçersiz seçim. Lütfen tekrar deneyin.\n";
            break;
        }
    }
}