"""
@file Basic_KMeans_Clustering.py
@brief Introduction to Machine Learning - K-Means Clustering
@note Explored during my senior year Data Science & AI electives.
      Using pure logic (no external ML libraries like sklearn) to show deep understanding.
"""

import math

def euclidean_distance(point1, point2):
    return math.sqrt(sum((x - y) ** 2 for x, y in zip(point1, point2)))

def k_means(data, k, iterations=10):
    # Initialize centroids simply as the first k points
    centroids = data[:k]
    
    for _ in range(iterations):
        # Create empty clusters
        clusters = [[] for _ in range(k)]
        
        # Assign points to the nearest centroid
        for point in data:
            distances = [euclidean_distance(point, c) for c in centroids]
            closest_index = distances.index(min(distances))
            clusters[closest_index].append(point)
            
        # Update centroids
        new_centroids = []
        for cluster in clusters:
            if not cluster:
                continue
            # Calculate mean of cluster
            cluster_mean = [sum(dim)/len(cluster) for dim in zip(*cluster)]
            new_centroids.append(cluster_mean)
            
        centroids = new_centroids
        
    return clusters, centroids

if __name__ == "__main__":
    # Sample 2D data points
    dataset = [[1, 2], [1, 4], [1, 0], [10, 2], [10, 4], [10, 0]]
    print("Running K-Means Clustering algorithm...")
    final_clusters, final_centroids = k_means(dataset, k=2)
    
    for i, cluster in enumerate(final_clusters):
        print(f"Cluster {i+1} Data Points: {cluster}")
        print(f"Centroid {i+1}: {final_centroids[i]}\n")