import networkx as nx
import matplotlib.pyplot as plt


G=nx.Graph()

#adding nodes
G.add_node('Berea College')
G.add_nodes_from(xrange(1,10))

#removing nodes
G.remove_node('Berea College')
G.remove_nodes_from([(1,2),(2,3)])

##add and remove nodes
G.add_edge(5,100)
G.remove_edge(5,100)

G.add_weighted_edges_from([(0,1,3.0),(1,4,7.5)])
G.add_path([1,2,3])

G.add_edge(1,3)
G[1][3]['color']='blue'

nx.draw(G,with_labels=True)

plt.show()
