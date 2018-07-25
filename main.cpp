#include <iostream>
#include <vector>

#include <dlib/clustering.h>
#include <dlib/rand.h>

using namespace std;
using namespace dlib;

int main(int argc, char** argv)
{
    long clusters_num;

    typedef matrix<double,2,1> sample_type;

    //typedef radial_basis_kernel<sample_type> kernel_type;
    //kcentroid<kernel_type> kc(kernel_type(0.001),0.01, 8);

    typedef histogram_intersection_kernel<sample_type> kernel_type;
    kcentroid<kernel_type> kc(kernel_type(),0.01, 8);

    //typedef radial_basis_kernel<sample_type> kernel_type; // for spectral_cluster
    //kcentroid<kernel_type> kc(kernel_type(0.25),0.01, 8); // for spectral_cluster


    kkmeans<kernel_type> test(kc);

    std::vector<sample_type> samples;
    std::vector<sample_type> initial_centers;

    sample_type m;

    try {    
        if (argc !=  2){
            std::cerr << "Usage: cat kkmeans_ex.txt | kkmeans n" << std::endl;
            return 1;
        }
        std::string str_clusters_num = argv[1];
        if(!std::all_of(str_clusters_num.begin(), str_clusters_num.end(), ::isdigit))
            throw std::invalid_argument("Invalid <n>");
        clusters_num = std::stoull(str_clusters_num);
        if(clusters_num == 0)
            throw std::invalid_argument("Invalid <n>");


        for(std::string line; std::getline(std::cin, line);){ 
            auto pos_x = line.find(';');
            if (pos_x == std::string::npos)
                throw std::invalid_argument("Invalid input x");
            auto pos_y = line.find('\n', pos_x + 1);
            if (pos_x == std::string::npos)  
                throw std::invalid_argument("Invalid input y");
            try {
                m(0) = std::stod(line.substr(0, pos_x));
                m(1) = std::stod(line.substr(pos_x + 1 , pos_y ));
                samples.push_back(m);
            }
            catch(const std::exception &e) {
                throw std::invalid_argument("Invalid input");
            }           
        }
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }


    test.set_number_of_centers(clusters_num);
    pick_initial_centers(clusters_num, initial_centers, samples, test.get_kernel());
  
    test.train(samples,initial_centers);


    for(auto const& s: samples){
        std::cout << s(0) << ";" << s(1) << ";cluster" << test(s) << std::endl;
    }

    /*
    std::vector<unsigned long> assignments = spectral_cluster(kernel_type(0.25), samples, clusters_num);
    int i = 0;
    for(auto const& s: samples){
        std::cout << s(0) << ";" << s(1) << ";cluster" << assignments[i++] << "\n";
    }
    */
}