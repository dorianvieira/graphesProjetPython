import csv
import networkx as nx
import matplotlib.pyplot as plt
from math import radians, cos, sin, asin, sqrt,atan2,acos

def calcDistance(lon1, lat1, lon2, lat2):
                   slat = radians(float(lat1))
                   slon = radians(float(lon1))
                   elat = radians(float(lat2))
                   elon = radians(float(lon2))

                   dist = 6371.01 * acos(sin(slat)*sin(elat) + cos(slat)*cos(elat)*cos(slon - elon))
                   print("La distance est de %.f min avec une vitesse de 60 km/h." % (60*(dist)/60))
                    

def csvFile():
        with open('gares.csv') as csvfile:
                readCSV = csv.reader(csvfile,delimiter=';')
                firstline = True
                for row in readCSV:
                    if firstline:    #skip first line
                        firstline = False
                    else:    
                        print ("\nStation 1 ",row[4])
                        print ("Station 2 ",row[10])
                        
                        calcDistance(row[0], row[1], row[11], row[12]) 
                        #print(row[0], row[1], row[11], row[12])   
                
def graph():
        #rerA
        g=nx.read_edgelist('rerALL.txt',create_using=nx.Graph(),nodetype=str,data=(('weight',float),))
        file = open("trainALL.txt")
        h=nx.Graph()
        color_map = []
        strings = file.read().split('\n')#recupere tout le contenu du fichier
        print(strings)
        station1 = input('Station de depart (exemple "CERGY-LE-HAUT" entre quotes): ')
        station2 = input('Station de fin (exemple "CERGY-PREFECTURE" entre quotes): ')
        if(station1 or station2 in strings): 
                print("Station1 :",station1)
                print("Station2 :",station2)
                print("Stations trouvees")
        else:
                print("Station2 :",station2)
                print("Stations non trouvees")
        pathlengths = []
        colornode = []
        
        for v in g.nodes(): #parcours les sommets et avec le + cours chemin
                spl = dict(nx.single_source_shortest_path_length(g, v))
                print('{} {} '.format(v, spl))
                station1 is v
                print("Station 1 : ",station1)
                colornode.append('red')
                
                
                for p in spl:  #mettre dans un tableau le resultat
                         pathlengths.append(spl[p])
        #if(station1 is not station2):
        #                nx.draw(g,with_labels=True,node_color=colornode,font_family='sans-serif')
        print (nx.info(g))
        pos = nx.spring_layout(g,scale=10)
        for n, p in pos.iteritems():
                g.node[n]['pos'] = p
        labels = nx.get_edge_attributes(g,'weight')
     	
        
        tab=nx.dijkstra_path(g,station1,station2)
        i=1
        
        for var in tab:
                h.add_node(var,pos=(6,i),color='b')
                h.add_edge(station1,var)
                station1=var
                color_map.append('red')
                      
        print('Le plus court chemin est : ',tab)
        nx.draw(h,node_color=color_map,with_labels=True,label=labels)
        
        #nx.draw(g,pos,with_labels=True,node_color=colornode,font_size=8)
        #nx.draw_networkx_edges(g, pos,edgelist=g.edges(),alpha=0.9, style='solid', edge_color='blue',label='weight')	
            
        plt.show()

def main():
      #csvFile()
      graph() 

if __name__ == "__main__":
        main()
                        

                        



