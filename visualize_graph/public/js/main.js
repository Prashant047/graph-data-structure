
const drawGraph = (nodes,edges) => {

    var nodes = new vis.DataSet(nodes);

    // create an array with edges
    var edges = new vis.DataSet(edges);

    // create a network
    var container = document.getElementById('container');

    // provide the data in the vis format
    var data = {
        nodes: nodes,
        edges: edges
    };
    var options = {
        edges:{
            arrows: {
                to: {enabled: true, scaleFactor:1, type:'arrow'},
                from: {enabled: true, scaleFactor:1, type:'arrow'}
            },
            smooth: false
        },
        nodes:{
            shape: 'circle',
            size: 50
        },
        physics: {
            barnesHut: {
            gravitationalConstant: -5850,
            avoidOverlap: 0.4
            },
            minVelocity: 0.75
        }

        
    };

    // initialize your network!
    var network = new vis.Network(container, data, options);
    
};


const socket = io.connect("http://localhost:8082");
socket.on('some', (data) => {
    // console.log(data.nodes);
    // console.log(data.links);

    drawGraph(data.nodes, data.edges);
});

