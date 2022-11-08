//================================================
/**
 * @file       Node.h
 *
 * rrybarcz
 */
//================================================

#ifndef NODE_H
#define NODE_H

/**
 * @class Node
 *
 * Implementation of a Node
 */
class Node
{
	public:		
		/// Constructor
		Node(int data);
		
		/// Destructor
		virtual ~Node();
		
		/// Getters/Setters - Accessor Methods
		
		/**
		 * Gets the Nodes Integer value.
		 *
		 * @return		Integer
		 */
		virtual int getData();
				
		/**
		 * Sets the value of the Node
		 *
		 * @param[in]          Integer		data
		 */
		virtual void setData(int data);
		
	private:		
		int data_;
		
	protected:
		/// Constructor (Default)
		Node() {}
};

#endif