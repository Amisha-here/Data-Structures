class ListNode{
    constructor(data)
    {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor(head = null) {
        this.head = head
    }

    clear() {
        this.head = null;
    }

    size(){
        let count = 0;
        let node = this.head;
        while(node) {
            count++; 
            node = node.next
        }
        return count;
    }
  
    getLast(){
        let lastNode = this.head;
        if(lastNode) {
            while(lastNode.next) {
                lastNode = lastNode.next
            }
        }
        return lastNode.data;
    }
    
    getFirst() {
        return this.head.data;
    }

}

let firstNode = new ListNode(3);
let secondNode = new ListNode(7);
let thirdNode = new ListNode(10);
let fourthNode = new ListNode(2);

firstNode.next = secondNode;
secondNode.next = thirdNode;
thirdNode.next = fourthNode;

let list = new LinkedList(firstNode);


console.log("Get second cell data",list.head.next.data);

console.log("Get size list",list.size());

console.log("Get last of list",list.getLast());

console.log("Get first of list",list.getFirst());

