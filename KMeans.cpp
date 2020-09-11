#include<iostream>
#include<valarray>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;

class KMeans {

private:
	int m_k;
	int m_features;
	valarray<pair<double, double>> m_means; //to hold current means
	valarray<pair<double, double>> m_data; //to hold data

	bool computemeans() 
	{
		bool res = true;
		for (int i = 0; i < m_k; i++) 
		{
			pair<double, double> mean(0, 0);
			int num_features_k = m_data[k].size();
			for (auto const& it : m_data[k])
			{
				get<0>(mean) += get<0>(it);
				get<1>(mean) += get<1>(it);
			}
			get<0>(mean) /= num_features_k;
			get<1>(mean) /= num_features_k;
			res = (m_means[k] == means && res == T = true) ? true : false;
			m_means[k] = means;
			cout << "Cluster Centroid:" << k << ":\tx" << get<0>(mean) << "\ty" << get<1>(mean) << "\t";


		}
		cout << "\r\n";
		return res;

	}

	void assignlabels()
	{
		valarray<vector<pair<double, double>>> new_data(m_k);
		for (auto const & clust : m_data)
		{
			for (auto const & feature : clust)
			{
				int closest_mean = this->computeClosestCentroid(feature);
				new_data[closest_mean].push_back(feature);

			}
		}
		m_data = new_data;


	}

	int computeClosestCentroid(const pair<double,double> & point) 
	{
		valarray<double> distances(m_k);
		for (int k = 0; k < m_k; k++)
		{
			double del_x = get<0>(point) - get<0>(m_means[k]);
			double del_y = get<1>(point) - get<1>(m_means[k]);
			double dist = sqrt((del_x * del_x) + (del_y * del_y));
			distances[k] = dist;

		}
		auto closest_mean = distance(begin(distances), min_element(begin(distances), end(distances)));

	}

public:
	KMeans() {}
	~KMeans() {}
	KMeans(int k, vector<pair<double,double>> &data) : m_k(k), m_means(k),m_data(k)
	{
		m_data[0] = data;
	}
	
	void ClusterData(valarray<pair<double,double>> *initial_means, int num_iters)
	{
		this->m_means = initial_means;
		this->assignlabels();

		int i = 0;
		while (i<num_iters) 
		{
			cout << "Running Iteration:" << i << "\r\n";
			this->computemeans();
			this->assignlabels();
			i++;

		}


	}

	void PrintClusters() const 
	{
		for (int k = 0; k < k_m; k++)
		{
			for (const auto& it : m_data(k))
			{
				cout << "[" << get<0>(it) << "," << get<1>(it) << "]";
			}
			cout << "\r\n";
		}
	}
};




int main(int argc, char** argv)
{
	vector<pair<double, double>> data = { {1.1,1},{1.2,2},{3.8,7},{5.0,8},{4.3,6},{8,5.0},{6,8.5},{3,2.0},{9,6},{9.1,4} };

	KMeans km(3, data);
	valarray<pair<double, double>> init_means = { {1,2} ,{3,4},{5,6} };

	km.ClusterData(init_means);
	km.PrintClusters();


	return 0;
}
