// Ajim1106-C-Mini-Project

// see update movie func before running code 


#include<iostream>
#include <string>

using namespace std;

class Movie {
private:
    string title;
    string genre;
    float rating;
    float price;

public:
    // Constructor
    Movie(string t = "", string g = "", float r = 0.0, float p = 0.0) {
        title = t;
        genre = g;
        rating = r;
        price = p;
    }

    // Setters
    void setTitle(string t){
    	title = t;
	}
	   
    void setGenre(string g) {
	 genre = g; 
	 }
	 
    void setRating(float r) {
	 rating = r; 
	 }
	 
    void setPrice(float p) {
	 price = p; 
	 }

    // Getters
    string getTitle() { 
	return title;
	 }
	 
    string getGenre() { 
	return genre; 
	}
	
    float getRating() { 
	return rating;
	 }
	 
    float getPrice() {
	 return price; 
	 }

    // Display Movie Info
    void displayMovie() {
        cout << "Title: " << title <<endl;
        cout << "Genre: " << genre << endl;
        cout << "Rating: " << rating << endl;
        cout << "Price: $" << price << endl;
    }
};


// 2nd class 
class MovieBookingSystem {
private:
    Movie movies[5]; //max enter 5 movies 
    int movieCount;

public:
    // Constructor
    MovieBookingSystem() {
        movieCount = 0;
    }

    // Create: Add a new movie
    void addMovie() {
        if (movieCount < 5) {
            string title, genre;
            float rating, price;

            cout << "Enter Movie Title: " <<endl;
            getline(cin, title);
            
            cout << "Enter Movie Genre: ";
            getline(cin, genre);
            
            cout << "Enter Movie Rating: ";
            cin >> rating;
            
            cout << "Enter Movie Price: ";
            cin >> price;

            // Create the Movie object and add it to the array
            movies[movieCount] = Movie(title, genre, rating, price);
            movieCount++;
            cout << "Movie added successfully!" << endl;
        } 
		else {
            cout << "Cannot add more movies. Limit reached!" << endl;
        }
    }

    // Read: View all movies
    void viewMovies() {
        if (movieCount == 0) {
            cout << "No movies available!" << endl;
            return;
        }

        for (int i = 0; i < movieCount; i++) {
            cout << "\nMovie " << i + 1 << " details:" << endl;
            movies[i].displayMovie();
        }
    }

    // Update: Update an existing movie by title
    
    /* void updateMovie() {
        string title;
        cout << "Enter the title of the movie you want to update: ";
        cin.ignore();
        getline(cin, title);

        bool found = false;
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].getTitle() == title) {
                found = true;

                string newTitle, newGenre;
                float newRating, newPrice;

                cout << "Enter new Title: ";
                getline(cin, newTitle);
                cout << "Enter new Genre: ";
                getline(cin, newGenre);
                cout << "Enter new Rating: ";
                cin >> newRating;
                cout << "Enter new Price: ";
                cin >> newPrice;

                movies[i].setTitle(newTitle);
                movies[i].setGenre(newGenre);
                movies[i].setRating(newRating);
                movies[i].setPrice(newPrice);

                cout << "Movie updated successfully!" << endl;
                break;
            }
        }

        if (!found) {
            cout << "Movie with the given title not found!" << endl;
        }
    }

    // Delete: Delete a movie by title
    void deleteMovie() {
        string title;
        cout << "Enter the title of the movie you want to delete: ";
        cin.ignore();
        getline(cin, title);

        bool found = false;
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].getTitle() == title) {
                found = true;

                // Shift all movies after the deleted movie to the left
                for (int j = i; j < movieCount - 1; j++) {
                    movies[j] = movies[j + 1];
                }

                movieCount--;
                cout << "Movie deleted successfully!" << endl;
                break;
            }
        }

        if (!found) {
            cout << "Movie with the given title not found!" << endl;
        }
    }
*/

    // Menu to interact with the system
    void showMenu() {
        int choice;
        do {
            cout << "\nMovie Booking System Menu:\n"
                 << "1. Add Movie\n"
                 << "2. View Movies\n"
//                 << "3. Update Movie\n"
                 << "4. Delete Movie\n"
                 << "5. Exit\n"
                 << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addMovie();
                    break;
                case 2:
                    viewMovies();
                    break;
                case 3:
                    updateMovie();
                    break;
                case 4:
                    deleteMovie();
                    break;
                case 5:
                    cout << "Exiting the system." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 5);
    }
};

int main(){
	
	MovieBookingSystem system;
    system.showMenu();
    
    return 0;
}



